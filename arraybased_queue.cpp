#include<iostream>
#include<new>
#include<algorithm>
using namespace std;

typedef struct queue{
    int *arr;
    int head;
    int tail;
    int count;
    int size;
    queue(int _size, int _head=0, int _tail=0, int _count=0){
        arr=new int[_size];
        head=_head;
        tail=_tail;
        count=_count;
        size=_size;
    }
};

queue* queue_create(int size){
    queue* q=new queue(size);
    return q;
}

void queue_resize(queue &q, int newsize){
    int *newarr=new int[newsize];
    for(int i=0; i<q.count; i++){
        newarr[i]=q.arr[(q.head+i)%q.size];
    }
    delete(q.arr);
    q.arr=newarr;
    q.head=0;
    q.tail=q.count;
    q.size=newsize;
}

void queue_add_first(queue &q, int val){
    if(q.size==q.count){
        queue_resize(q, q.size*2);
    }
    q.head=(q.head-1+q.size)%q.size;
    q.arr[q.head]=val;
    q.count++;
}

int queue_remove_first(queue &q){
    if(q.count==0){
        return 0;
    }
    int val=q.arr[q.head];
    q.head=(q.head+1)%q.size;
    q.count--;
    if(q.count>0&&q.count==q.size/4){//赋值表达式不能并联
        queue_resize(q, q.size/2);
    }
    return val;
}

void queue_add_last(queue &q, int val){
    if(q.count==q.size){
        queue_resize(q, q.size*2);
    }
    q.arr[q.tail]=val;
    q.tail=(q.tail+1)%q.size;
    q.count++;
}

int queue_remove_last(queue &q){
    if(q.count==0){
        return 0;
    }
    q.tail=(q.tail-1+q.size)%q.size;
    int val=q.arr[q.tail];
    if(q.count>0&&q.count==q.size/4){
        queue_resize(q, q.size/2);
    }
    return val;
}

int array_get_first(queue &q){
    return q.arr[q.head];
}

int array_get_last(queue &q){
    return q.arr[(q.tail-1)%q.size];
}

bool queue_Is_full(queue &q){
    return q.tail+1==q.head;//q.count==q.size-1
    //q.count==q.size
}

int queue_size(queue &q){
    return q.size;
}

bool queue_Is_empty(queue &q){
    return q.count==0;
}
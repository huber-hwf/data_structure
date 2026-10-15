#include<iostream>
#include<new>
#include<algorithm>
#include<cstdlib>
#include<string>
using namespace std;

typedef struct Node{
    string key;
    int val;
    Node* next;
    Node(string _key, int _val, Node* _next=NULL){
        copy_n(_key, _key.size(), key);
        val=_val;
    }
};

typedef struct Hashtable{
    Node** buckets;
    int size;
    int count;
    Hashtable(int _size, int _count=0){
        buckets=new Node*[_size];//构造函数里面内存分配失败了外面也会分配失败
        size=_size;
        count=_count;
    }
};

unsigned long long hashStr(const string s){
    unsigned long long h=0;
    for(int i=0; s[i]; i++) h=h*31+(unsigned char)s[i];/*unsigned char不能被改成
    unsigned int，因为uc范围是0~255，如果是负数，s[i]的值会被转化得很大，有溢出的风险*/
    return h;
}

Hashtable* hashtable_create(int size){
    Hashtable* ht=new Hashtable(size);//结构体有构造函数不能直接new， 没有的时候可以；
    if(!ht) return NULL;//new失败之后不会返回NULL；
    return ht;
}

Node* newnode(const string key, int val){
    Node* node=new Node(key, val);
    if(!node) return NULL;
    return node;
}

bool Rehash(Hashtable* ht, int newsize){
    if(!ht) return false;
    Node** nb=(Node** )calloc(newsize, sizeof(Node*));
    if(!nb) return false;
    Node** temp=ht->buckets;
    ht->buckets=nb;
    Node* p=temp[0];
    int i=0;
    while(i<ht->size){
        if(p){
            unsigned long long b=hashStr(p->key)%newsize;
            Node* newp=p;
            newp->next=ht->buckets[b];
            ht->buckets[b]=newp;
            p=p->next;
        }
        else{i++; p=temp[i];}
    }
    free(temp);
    ht->size=newsize;
    return true;
}

bool RehashIsneeded(Hashtable *ht){
    if(!ht) return false;
    if(ht->count*1.0/ht->size<=0.75) return false;
    return true;
}

bool Check_and_Rehash(Hashtable* ht){
    if(!RehashIsneeded(ht)) return false;
    Rehash(ht, ht->size*2);
    return true;
}

void hashPut(Hashtable* ht, const string key, int val){
    Check_and_Rehash(ht);
    unsigned long long h=hashStr(key)%ht->size;
    for(Node* p=ht->buckets[h]; p; p=p->next){
        if(p->key==key) p->val=val;
    }
    Node* n=newnode(key, val);
    n->next=ht->buckets[h];
    ht->buckets[h]=n;
    ht->count++;
}

bool htGet(Hashtable* ht, const string key, int &out){
    if(!ht) return false;
    unsigned long long h=hashStr(key)%ht->size;
    for(Node* p=ht->buckets[h]; p; p=p->next){
        if(p->key==key) {out=p->val; return true;}
    }
    return false;
}

bool htRemove(Hashtable* ht, const string key, int& out){
    if(!ht) return false;
    unsigned long long h=hashStr(key)%ht->size;
    Node** p=&ht->buckets[h];
    while(p){
        if((*p)->key==key){
            Node* dead=*p;
            out=dead->val;
            *p=dead->next;
            free(dead);
            ht->count--;
            return true;
        }
        else p=&(*p)->next;//优先级："->" > "*" > "&";
    }
    return false;
}

void htfree(Hashtable* ht){
    if(ht){
        int i=0;
        Node* p=ht->buckets[i];
        while(i<ht->size){
            if(p){
                Node* todel=p;
                p=p->next;
                free(todel);//string变量是栈上的，只有堆上的才需要delete
            }
            else{i++; p=ht->buckets[i];}
        }
        free(ht->buckets);
        free(ht);
        ht=NULL;//free掉之后指针不会变成NULL， 堆内存上的对象可能也不会变
    }
}
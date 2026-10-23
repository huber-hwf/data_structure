#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct Node{
    ElemType data;
    struct Node *next;
};

typedef struct Node *Linklist;

Status GetElem(Linklist L, int i, ElemType *e){
    int j;
    Linklist p=L->next;
    j=1;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    if(!p||j>i) return ERROR;
    *e=p->data;
    return OK;
}

Status ListInsert(Linklist *L, int i, ElemType e){
    int j;
    Linklist p, s;
    p=*L;
    j=1;
    while(p&&j<i){
        p=p->next;
        ++j;
    }
    if(!p&&j>i){
        return ERROR;
    }
    s=(Linklist)malloc(sizeof(Node));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

Status ListDelete(Linklist *L, int i, ElemType *e){
    int j;
    Linklist p=*L;
    j=1;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    if(!p||j>i) return ERROR;
    Linklist q=p->next;
    p->next=q->next;
    *e=q->data;
    free(q);
    return OK;
}
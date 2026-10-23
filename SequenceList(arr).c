#include<stdio.h>

#define MAXSIZE 200
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct{
    ElemType data[MAXSIZE];
    int length;
}Sqlist;

Status GetElem(Sqlist L, int i, int *e){
    if(L.length==0) return ERROR;
    if(i<1||i>L.length) return ERROR;
    *e=L.data[i-1];
    return OK;
}

Status ListInsert(Sqlist *L, int i, int e){
    if(L->length==MAXSIZE) return ERROR;
    if(i<1||i>L->length+1) return ERROR;
    if(i!=L->length+1){
        for(int k=L->length; k>=i; k--){
            L->data[k]=L->data[k-1];
        }
    }
    L->data[i-1]=e;
    L->length++;
    return OK;
}

Status ListDelete(Sqlist *L, int i, int *e){
    if(L->length==0) return ERROR;
    if(i<1||i>L->length) return ERROR;
    *e=L->data[i-1];
    if(i!=L->length){
        for(int k=i-1; k<L->length-1; k++){
            L->data[k]=L->data[k+1];
        }
    }
    L->length--;
    return OK;
}
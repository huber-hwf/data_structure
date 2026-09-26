#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR -1

typedef int typ;

typedef struct node {
    typ val;
    struct node* prv;
    struct node* next;
} node;

typedef struct {
    node* head;
    node* tail;
    int size;
} Mylinkedlist;

node* createnode (typ e) {
    node* newnode = (node* ) malloc (sizeof(node));
    newnode->val = e;
    newnode->prv = NULL;
    newnode->next = NULL;
    return newnode;
}

Mylinkedlist* Mylinkedlistcreate (void) {
    Mylinkedlist* list = (Mylinkedlist*) malloc (sizeof(Mylinkedlist));
    list->head = createnode(0);
    list->tail = createnode(0);
    list->head->next = list->tail;
    list->tail->prv = list->head;
    list->size = 0;
    return list;
}

bool isElementIndex (Mylinkedlist* list, int index) {
    return index >= 0 && index < list->size;
}

bool isPositionIndex (Mylinkedlist* list, int index) {
    return index >= 0 && index <= list->size;
}

void CheckElementIndex (Mylinkedlist* list, int index) {
    if (!isElementIndex (list, index)) {
        printf ("Index: %d  Size: %d\n", index, list->size);
        exit (1);
    }
}

void CheckPositionIndex (Mylinkedlist* list, int index) {
    if (!isPositionIndex (list, index)) {
        printf ("Index: %d  Size: %d\n", index, list->size);
        exit (1);
    }
}

node* Getnode (Mylinkedlist* list, int index) {
    CheckElementIndex (list, index);
    node* p = list->head->next;
    for (int i = 0; i < index; i++){
        p = p->next;
    }
    return p;
}

/*****ADD*****/

void Addlast (Mylinkedlist* list, typ e) {
    node* x = (node* ) malloc (sizeof(node));
    if (!x) return;
    node* temp = list->tail->prv;
    x->val = e;
    list->tail->prv = x;
    x->next = list->tail;
    temp->next = x;
    x->prv = temp;
    list->size++;
}

void Addfirst (Mylinkedlist* list, typ e) {
    node* x = (node* ) malloc (sizeof(node));
    if(!x) return;
    x->val = e;
    node* temp = list->head->next;
    list->head->next = x;
    x->prv = list->head;
    x->next = temp;
    temp->prv = x;
    list->size++;
}

void Addnode (Mylinkedlist* list, typ e, int index) {
    CheckPositionIndex (list, index);
    if (index == list->size){
        Addlast (list, e);
        return;
    }
    node* p = Getnode (list, index);
    node* temp = p->prv;
    node* x = createnode (e);
    if (!x) return;
    p->prv = x;
    x->next = p;
    temp->next = x;
    x->prv = temp;
    list->size++;
}

/*****删*****/

typ removeFirst (Mylinkedlist* list) {
    if (list->size < 1) {
        printf ("No elements to remove");
        exit (1);
    }
    node* x = list->head->next;
    if (!x) return;
    typ val = x->val;
    node* temp = x->next;
    list->head->next = temp;
    temp->prv = list->head;
    free (x);
    list->size--;
    return val;
}

typ removelast (Mylinkedlist* list) {
    if (list->size < 1) {
        printf ("No element to remove\n");
        exit (1);
    }
    node* x = list->tail->prv;
    if (!x) return;
    typ val = x->val;
    node* temp = x->prv;
    temp->next = list->tail;
    list->tail->prv = temp;
    free (x);
    return val;
}

typ removeAT (Mylinkedlist* list, int index) {
    CheckElementIndex (list, index);
    node* x = Getnode (list, index);
    typ val = x->val;
    node* temp = x->prv;
    temp->next = x->next;
    x->next->prv = temp;
    free (x);
    list->size--;
    return val;
}

/*****查*****/

typ get (Mylinkedlist* list, int index) {
    CheckElementIndex (list, index);
    node* p = Getnode (list, index);
    return p->val;
}

typ getFirst (Mylinkedlist* list) {
    if (list->size < 1) {
        printf ("No element in the list\n");
        exit (1);
    }
    return list->head->next->val;
}

typ getLast (Mylinkedlist* list) {
    if (list->size < 1) {
        printf ("No element in the list\n");
        exit (1);
    }
    return list->tail->prv->val;
}

/*****改*****/

typ set (Mylinkedlist* list, int index, typ e) {
    CheckElementIndex (list, index);
    node* p = Getnode (list, index);
    typ oldval = p->val;
    p->val = e;
    return oldval;
}

/*****工具函数*****/

int size (Mylinkedlist* list) {
    return list->size;
}

bool isEmpty (Mylinkedlist* list) {
    return list->size == 0;
}

void display (Mylinkedlist* list) {
    printf ("size == %d\n", list->size);
    for (node* p = list->head->next; p != list->tail; p = p->next) {
        printf ("%d <-> ", p->val);
    }
    printf ("NULL\n");
}

void mylinkedlistfree (Mylinkedlist* list) {
    while (list->size != 0) {
        removeFirst (list);
    }
    free (list->head);
    free (list->tail);
    free (list);
}

int main () {
    Mylinkedlist* list = Mylinkedlistcreate ();
    Addlast (list, 1);
    Addlast (list, 2);
    Addlast (list, 3);
    Addfirst (list, 0);
    Addnode (list, 100, 2);
    display (list);
    mylinkedlistfree (list);
    return 0;
}
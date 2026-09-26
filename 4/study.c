#include <stdio.h>
#include <stdlib.h>

typedef int typ;

typedef struct Listnode {
        int val;
        struct Listnode* next;
    }Listnode;

typedef struct DListnode {
        int val;
        struct DListnode *prv, *next;
    }DListnode;

void traverse (Listnode* head) {
    for (Listnode* p = head; p; p = p->next) {
        printf ("%d\n", p->val);
    }
}

Listnode* createLinkedList (typ* arr, int arrSize) {
    if (!arr || arrSize == 0) return NULL;
     Listnode* head = (Listnode* ) malloc (sizeof(Listnode));
     head->next = NULL;
     Listnode* cur = head;
     head->val = arr[0];
     for (int i = 1; i < arrSize; i++) {
        cur->next = (Listnode* ) malloc (sizeof(Listnode));
        cur->next->val = arr[i];
        cur->next->next = NULL;
        cur = cur->next;
     }
     return head;
}

void insert_newhead (Listnode** head, typ e) {
    Listnode* newhead = (Listnode* ) malloc (sizeof(Listnode));
    newhead->val = e;
    newhead->next = *head;
    *head = newhead;
}

void insert_newtail (Listnode* head, typ e) {
    Listnode* newtail = head;
    while (newtail->next) {
        newtail = newtail->next;
    }
    newtail->next = (Listnode* ) malloc (sizeof(Listnode));
    newtail->next->val = e;
    newtail->next->next = NULL;
}

void insert_newnode (Listnode* head, typ e, int place) {
    Listnode* p = head;
    for (int i = 0; i < place - 2; i++){
        p = p->next;
    }
    Listnode* newnode = (Listnode* ) malloc (sizeof(Listnode));
    newnode->val = e;
    newnode->next = p->next;
    p->next = newnode;
}

void delete_node (Listnode* head, int place) {
    Listnode* p = head;
    for (int i = 0; i < place - 2; i++){
        p = p->next;
    }
    Listnode* todelete = p->next;
    p->next = todelete->next;
    free (todelete);
}

void delete_tail (Listnode* head) {
    Listnode* p = head;
    while  (p->next->next) {
        p = p->next;
    }
    Listnode* todelete = p->next;
    p->next = NULL;
    free (todelete);
}

void delete_head (Listnode** head) {
    Listnode* todelete = *head;
    *head = (*head)->next;
    free (todelete);
}

DListnode* createdlinkedlist (typ* arr, int arrsize) {
    if (!arr || arrsize == 0) return NULL;
    DListnode* head = (DListnode* ) malloc (sizeof(DListnode));
    head->val = arr[0];
    head->prv = NULL;
    head->next = NULL;
    DListnode* cur = head;
    for (int i = 1; i < arrsize; i++) {
        cur->next = (DListnode* ) malloc (sizeof(*head));
        cur->next->val = arr[i];
        cur->next->next = NULL;
        cur->next->prv = cur;
        cur = cur->next;
    }
    return head;
}

void dtraverse (DListnode*head) {
    DListnode* tail = head;
    for (DListnode* p = head; p; p = p->next) {
        printf ("%d\n", p->val);
        tail = p;
    }
    for (DListnode* p = tail; p; p = p->prv) {
        printf ("%d\n", p->val);
    }
}

void insert_dnewhead (DListnode** head, typ e) {
    DListnode* newhead = (DListnode* ) malloc (sizeof(DListnode));
    newhead->val = e;
    newhead->next = *head;
    newhead->prv = NULL;
    (*head)->prv = newhead;
    *head = newhead;
}

void insert_dnewnode (DListnode* head, int place, typ e) {
    DListnode* p = head;
    for (int i = 0; i < place - 2; i++){
        p = p->next;
    }
    DListnode* dnewnode = (DListnode* ) malloc (sizeof(DListnode));
    dnewnode->val = e;
    dnewnode->next = p->next;
    p->next->prv = dnewnode;
    p->next = dnewnode;
    dnewnode->prv = p;
}

void insert_dnewtail (DListnode* head, typ e) {
    DListnode* tail = (DListnode* ) malloc (sizeof(DListnode));
    tail->val = e;
    DListnode* p = head;
    for (p; p->next; p = p->next);
    p->next = tail;
    tail->prv = p;
    tail->next = NULL;
}

void delete_dnode (DListnode* head, int place) {
    DListnode* p = head;
    for (int i = 0; i < place - 2; i++) {
        p = p->next;
    }
    DListnode* todelete = p->next;
    p->next = todelete->next;
    todelete->next->prv = p;
    free (todelete);
}

void delete_dtail (DListnode* head) {
    DListnode* p = head;
    while (p->next->next) {
        p = p->next;
    }
    DListnode* todelete = p->next;
    p->next = NULL;
    free (todelete);
}

void delete_dhead (DListnode** head) {
    DListnode* todelete = *head;
    *head = (*head)->next;
    free (todelete);
    (*head)->prv = NULL;
}

int main () {
    int arr[] = {1, 2, 3, 4, 5};
    Listnode* head = createLinkedList (arr, 5);
    insert_newhead (&head, 0);
    insert_newtail (head, 8);
    insert_newnode (head, 6, 7);
    insert_newnode (head, 7, 8);
    delete_node (head, 9);
    delete_tail (head);
    traverse (head);
    DListnode* dhead = createdlinkedlist (arr, 5);
    dtraverse (dhead);
    return 0;
}
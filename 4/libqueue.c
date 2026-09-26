#include <stdio.h>
#include <stdlib.h>

typedef struct Listnode {
    int val;
    struct Listnode* next;
} Listnode;

typedef struct Mylinkedqueue {
    Listnode* head;
    Listnode* tail;
    int size;
} Mylinkedqueue;

Mylinkedqueue* mylinkedqueueCreate (void) {
    Mylinkedqueue* queue = (Mylinkedqueue* ) malloc (sizeof(Mylinkedqueue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

void mylinkedqueuePush (Mylinkedqueue* queue, int e) {
    Listnode* node = (Listnode* ) malloc (sizeof(Listnode));
    node->val = e;
    node->next = NULL;
    if (queue->tail) {
        queue->tail->next = node;
    }
    if (!queue->tail) {
        queue->head = node;
    }
    queue->tail = node;
    queue->size++;
}

int mylinkedqueuePop (Mylinkedqueue* queue) {
    if (!queue || !queue->size) exit(1);
    Listnode* node = queue->head;
    int val = node->val;
    queue->head = node->next;
    if (queue->size == 1) {
        queue->tail = NULL;
    }
    free (node);
    queue->size--;
    return val;
}

int mylinkedqueuePeek (Mylinkedqueue* queue) {
    return queue->head->val;
}

int mylinkedqueueSize (Mylinkedqueue* queue) {
    return queue->size;
}

void mylinkedqueueFree (Mylinkedqueue* queue) {
    while (queue->head) {
        Listnode* node = queue->head;
        queue->head = node->next;
        free (node);
    }
    free (queue);
}
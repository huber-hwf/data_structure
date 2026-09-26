#include <stdio.h>
#include <stdlib.h>

typedef struct Listnode {
    int val;
    struct Listnode* next
} Listnode;

typedef struct Mylinkedstack {
    Listnode* head;
    int size;
} Mylinkedstack;

Mylinkedstack* mylinkedstackCreate (void) {
    Mylinkedstack* stack = (Mylinkedstack* ) malloc (sizeof(Mylinkedstack));
    stack->head = NULL;
    stack->size = 0;
    return stack;
}

void mylinkedstackPush (Mylinkedstack* stack, int e) {
    Listnode* node = (Listnode* ) malloc (sizeof(Listnode));
    node->val = e;
    node->next = stack->head;
    stack->head = node;
    stack->size++;
}

int mylinkedstackPop (Mylinkedstack* stack) {
    int val = stack->head->val;
    Listnode* temp = stack->head;
    free (temp);
    stack->head = stack->head->next;
    stack->size--;
    return val;
}

int mylinkedstackPeek (Mylinkedstack* stack) {
    return stack->head->val;
}

int mylinkedstackSize (Mylinkedstack* stack) {
    return stack->size;
}

void mylinkedstackFree (Mylinkedstack* stack) {
    while (stack->head) {
        Listnode* node = stack->head;
        stack->head = node->next;
        free (node);
    }
    free (stack);
}
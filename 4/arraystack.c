#include <stdlib.h>
#include <stdio.h>

#define INIT_CP 1

typedef struct {
    int* data;
    int size;
    int cap;
} ArrayStack;

ArrayStack* arrayStack (void) {
    ArrayStack* stack = (ArrayStack* ) malloc (sizeof(ArrayStack));
    stack->data = (int* ) malloc (INIT_CP*sizeof(int));
    stack->cap = INIT_CP;
    stack->size = 0;
    return stack;
}

void arrayStackPush (ArrayStack* stack, int e) {
    if (stack->size == stack->cap) {
        int* temp;
        temp = (int* ) realloc (stack->data, 2*stack->cap * sizeof(int));
        if (temp == NULL) return;
        stack->data = temp;
        stack->cap *= 2;
    }
    stack->data[(stack->size)++] = e;
}

int arrayStackPop (ArrayStack* stack) {
    if (!stack || !stack->size) {
        printf ("NO element to pop.\n");
        return 0;
    }
    return stack->data[--stack->size];
}

int arrayStackPeek (ArrayStack* stack) {
    return stack->data[stack->size-1];
}

void arrayStackFree (ArrayStack* stack) {
    if (stack) free (stack->data);
    free (stack);
}

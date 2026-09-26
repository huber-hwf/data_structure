#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int *arr;
    int start;
    int end;
    int count;
    int size;
} CycleArray;

CycleArray* cycleArrayCreate (int size) {
    CycleArray* ca = (CycleArray* ) malloc (sizeof(CycleArray));
    ca->size = size;
    ca->arr = (int* ) calloc (size, sizeof(int));
    ca->start = 0;
    ca->end = 0;
    ca->count = 0;
    return ca;
}

void cycleArrayResize (CycleArray* ca, int newsize) {
    int* newarr = (int* ) calloc (newsize, sizeof(int));
    for (int i = 0; i < ca->count; i++) {
        newarr[i] = ca->arr[(ca->start + i) % ca->size];
    }
    free (ca->arr);
    ca->arr = newarr;
    ca->start = 0;
    ca->end = ca->count;
    ca->size = newsize;
}

void cycleArrayAddFirst (CycleArray* ca, int val) {
    if (ca->size == ca->count) {
        cycleArrayResize (ca, ca->size * 2);
    }
    ca->start = (ca->start - 1 + ca->size) % ca->size;
    ca->arr[ca->start] = val;
    ca->count++;
}

int cycleArrayRemoveFirst (CycleArray* ca) {
    if (ca->count == 0) {
        return 0;
    }
    int val = ca->arr[ca->start];
    ca->start = (ca->start + 1) % ca->size;
    ca->count--;
    if (ca->count > 0 && ca->count == ca->size / 4) {
        cycleArrayResize (ca, ca->size / 2);
    }
    return val;
}

void cycleArrayAddLast (CycleArray* ca, int val) {
    if (ca->count == ca->size) {
        cycleArrayResize (ca, ca->size * 2);
    }
    ca->arr[ca->end] = val;
    ca->end = (ca->end + 1) % ca->size;
    ca->count++;
}

int cycleArrayRemoveLast (CycleArray* ca) {
    if (ca->count = 0) {
        return 0;
    }
    ca->end = (ca->end - 1 + ca->size) % ca->size;
    int val = ca->arr[ca->end];
    ca->count--;
    if (ca->count > 0 && ca->count == ca->size / 4) {
        cycleArrayResize (ca, ca->size / 2);
    }
    return val;
}

int cycleArrayGetFirst (CycleArray* ca) {
    return ca->arr[ca->start];
}

int cycleArrayGetLast (CycleArray* ca) {
    return ca->arr[(ca->end - 1 + ca->size) % ca->size];
}

bool cycleArrayIsFull (CycleArray* ca) {
    return ca->count = ca->size;
}

int cycleArraySize (CycleArray* ca) {
    return ca->count;
}

bool cycleArrayIsEmpty (CycleArray* ca) {
    return ca->count == 0;
}

void cycleArrayFree (CycleArray* ca) {
    free (ca->arr);
    free (ca);
}

typedef struct {
    CycleArray* arr;
} ArrayQueue;

ArrayQueue* arrayQueueCreate (void) {
    ArrayQueue* queue = (ArrayQueue* ) malloc (sizeof(ArrayQueue));
    queue->arr = cycleArrayCreate (1);
    return queue;
}

void arrayQueuePush (ArrayQueue* queue, int e) {
    cycleArrayAddLast (queue->arr, e);
}

int arrayQueuePop (ArrayQueue* queue) {
    int val = queue->arr->arr[queue->arr->start];
    cycleArrayRemoveFirst (queue->arr);
    return val;
}
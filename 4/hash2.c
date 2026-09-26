#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define REMOVEKEY -1

typedef enum {EMPTY = 0, OCCUPIED = 1, TOMB = -1} SlotState;

typedef struct {
    int key;
    int val;
    SlotState state;
} Slot;

typedef struct {
    Slot* slots;
    int size;
    int count;
    int mode;
    int tombs;
    long probes;
} HashTables;

static int hashInt (int key, int size) {
    return (int) ((unsigned)key % (unsigned)size);
}

static int probeStep (int i, int mode, int h2) {
    if (h2 == 0 && (mode != 1 || mode != 2)) return -1;
    switch (mode) {
        case 1 : return i;
        case 2 : return i * i;
        default : return i * h2;
    }
}

HashTables* hashCreate (int size, int mode) {
    HashTables* t = calloc (1, sizeof(HashTables));
    if (!t) return NULL;
    t->slots = calloc (size, sizeof(Slot));
    if (!t->slots) {free (t); return NULL;}
    t->size = size;
    t->mode = mode;
    return t;
} 

bool htPut (HashTables* t, int key, int val) {
    if (!t) return false;
    int h = hashInt (key, t->size);
    int h2 = 1 + h % (t->size - 1);
    int firstTomb = -1;
    for (int i = 0; i < t->size; i++) {
        int pos = (h + probeStep (i, t->mode, h2)) % t->size;
        t->probes++;
        if (t->slots[pos].state == OCCUPIED) {
            if (t->slots[pos].key == key) {
                t->slots[pos].val = val;
                return true;
            }
        }
        if (t->slots[pos].state == TOMB) {
            if (firstTomb < 0) firstTomb = pos;
        }
        if (t->slots[pos].state == EMPTY) {
            int p = firstTomb >= 0 ? firstTomb : pos;
            int a = firstTomb >= 0 ? 1 : 0;
            t->slots[p].val = val;
            if (a) {
                t->slots[p].state = OCCUPIED; 
                t->tombs--;
            }
            t->slots[p].state = OCCUPIED;
            t->slots[p].key = key;
            t->count++;
            return true;
        }
    }
    return false;
}

bool htRemove (HashTables* t, int key, int* out) {
    if (!t || t->size == 0) return false;
    int h = hashInt (key, t->size);
    int h2 = 1 + h % (t->size - 1);
    for (int i = 0; i < t->size; i++) {
        int pos = (h + probeStep (i, t->mode, h2)) % t->size;
        if (t->slots[pos].key == key && t->slots[pos].state == OCCUPIED) {
            *out = t->slots[pos].val;
            t->slots[pos].key = REMOVEKEY;
            t->slots[pos].state = TOMB;
            t->count--;
            t->tombs++;
            return true;
        }
    }
    return false;
}

void htFree (HashTables* t) {
    if (t) free (t->slots);
    free (t);
}
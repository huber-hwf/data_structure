#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char* key;
    int val;
    struct Node* next;
} Node;

typedef struct  {
    Node** buckets;
    int size;
    int count;
} HashTable;

static unsigned long hashStr (const char* s) {
    unsigned long h = 0;
    for (int i = 0; s[i]; i++) h = h * 31 + (unsigned char) s[i];
    return h;
}

HashTable* htCreate (int size) {
    HashTable* t = (HashTable* ) malloc (sizeof(HashTable));
    if (!t) return NULL;
    t->size = size;
    t->count = 0;
    t->buckets = calloc (size, sizeof(Node* ));
    if (!t->buckets) {free (t); return NULL;}
    return t;
}

static Node* newNode (const char* key, int val) {
    Node* n = malloc (sizeof(Node));
    if (!n) {free (n); return NULL;}
    n->key = malloc (strlen(key) + 1);
    if (!n->key) return NULL;
    n->val = val;
    n->next = NULL;
    strcpy (n->key, key);
    return n;
}

bool htRehash (HashTable* t, int newsize) {
    if (!t) return false;
    Node** temp = t->buckets;
    Node** nb = calloc (newsize, sizeof(Node));
    if (!nb) {free (nb); return false;}
    t->buckets = nb;
    Node* p = temp[0];
    int i = 0;
    while (i < t->size) {
        if (p) {
            unsigned long b = hashStr (p->key) % newsize;
            Node* newp = p;
            newp->next = t->buckets[b];
            t->buckets[b] = newp;
            p = p->next;
        }
        else {i++; p = temp[i];}
    }
    t->size = newsize;
    free (temp);
    return true;
}

bool htResizeIfNeeded (HashTable* t) {
    if (!t) return false;
    if (t->count * 1.0 / t->size <= 0.75) return false;
    return true;
}

bool htResize (HashTable* t) {
    if (!t || !htResizeIfNeeded (t)) return false;
    htRehash (t, t->size * 2);
    return true;
}

void htPut (HashTable* t, const char* key, int val) {
    htResize (t);
    unsigned long b = hashStr (key) % t->size;
    for (Node* p = t->buckets[b]; p; p = p->next) {
        if (strcmp (p->key, key) == 0) {
            p->val = val;
            return;
        }
    }
    Node* n = newNode (key, val);
    n->next = t->buckets[b];
    t->buckets[b] = n;
    t->count++;
}

bool htGet (HashTable* t, const char* key, int* out) {
    if (!t) return false;
    unsigned long b = hashStr (key) % t->size;
    for (Node* p = t->buckets[b]; p; p = p->next) {
        if (strcmp (p->key, key) == 0) {
            *out = p->val;
            return true;
        }
    }
    return false;
}

bool htRemove (HashTable* t, const char* key, int* val) {
    if (!t) return false;
    unsigned long b = hashStr (key) % t->size;
    Node** pp = &t->buckets[b];
    while (*pp) {
        if (strcmp ((*pp)->key, key) == 0) {
            Node* dead = *pp;
            *val = dead->val;
            *pp = dead->next;
            free (dead->key);
            free (dead);
            return true;
        }
        pp = &(*pp)->next;
    }
    return false;
}

void htFree (HashTable* t) {
    if (t) {
        int i = 0;
        Node* p = t->buckets[i];
        while (i < t->size) {
            if (p) {
                Node* todelete  = p;
                p = p->next;
                free (todelete->key);
                free (todelete);
            }
            else {i++; p = t->buckets[i];}
        }
        free (t->buckets);
    }
    free (t);
}
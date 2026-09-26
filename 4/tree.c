#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum {P=1, I=2, L=3} order;

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right; 
} Node;

Node* make (int v) {
    Node* n = (Node* ) malloc (sizeof(Node));
    if (!n) return NULL;
    n->val = v;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void free_tree (Node* root) {
    if (!root) return;
    free_tree (root->left);
    free_tree (root->right);
    free (root);
}

Node* build_tree (void) {
    Node* n4 = make (4);
    Node* n5 = make (5);
    Node* n6 = make (6);
    Node* n2 = make (2); n2->left = n4; n2->right = n5;
    Node* n3 = make (3); n3->right = n6;
    Node* n1 = make (1); n1->left = n2; n1->right = n3;
    return n1;
}

int res[16];
int cnt = 0;
void visit (int v) { res[cnt++] = v;}

void rec_traverse (Node* n, int order) {
    if (!n) return;
    if (order == P) {
         visit (n->val); rec_traverse (n->left, order); rec_traverse (n->right, order);
        }
    else if (order == I) {
         rec_traverse (n->left, order); visit (n->val); rec_traverse (n->right, order);
    }
    else {
         rec_traverse (n->left, order); rec_traverse (n->right, order); visit (n->val);
    }
}

typedef struct Stack {
    Node** data;
    int top;
    int cap;
} Stack;

Stack* st_new (int cap) {
    Stack* s = (Stack* ) malloc (sizeof(Stack));
    if (!s) return NULL;
    s->data = (Node** ) malloc (sizeof(Node*) * cap);
    if (!s->data) { free (s); return NULL;}
    s->top = 0;
    s->cap = cap;
    return s;
}

void st_push (Stack* s, Node* n) {
    s->data[s->top++] = n;
}

bool st_empty (Stack* s) {
    return s->top == 0;
}


Node* st_pop (Stack* s) {
    Node* n = s->data[--s->top];
    return n;
}

void st_free (Stack* s) {
    if (!s) return;
    free (s->data);
    free (s);
}

void pre_iter (Node* root) {
    Stack* s = st_new (16);
    if (!s) return;
    if (root) st_push (s, root);
    while (!st_empty (s)) {
        Node* n = st_pop (s);
        visit (n->val);
        if (n->right) st_push (s, n->right);
        if (n->left) st_push (s, n->left);
    }
    st_free (s);
}

typedef struct {
    Node** data;
    int head, tail;
    int cap;
} Queue;

Queue* q_new (int cap) {
    Queue* q = (Queue* ) malloc (sizeof(Queue));
    if (!q) return NULL;
    q->data = (Node** ) malloc (sizeof(Node*) * cap);
    if (!q->data) { free (q); return NULL;} 
    q->head = q->tail = 0;
    q->cap = cap;
    return q;
}

bool q_empty (Queue* q) {
    return q->head == q->tail;
}

void q_push (Queue* q, Node* n) {
    q->data[q->tail++] = n;
    q->tail %= q->cap;
}

Node* q_pop (Queue* q) {
    Node* n = q->data[q->head++];
    q->head %= q->cap;
    return n;
}

void q_free (Queue* q) {
    if (!q) return;
    free (q->data);
    free (q);
}

void level_order (Node* root) {
    Queue* q = q_new (16);
    if (!q) return;
    if (root) q_push (q, root);
    while (!q_empty (q)) {
        Node* n = q_pop (q);
        visit (n->val);
        if (n->left) q_push (q, n->left);
        if (n->right) q_push (q, n->right);
    }
    q_free (q);
}

void print_res (void) {
    for (int i = 0; i < cnt; i++)
    printf ("%d ", res[i]);
    printf ("\n");
}
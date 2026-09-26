#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left, * right;
} Node;

 Node* make (int v) {
    Node* n = (Node* ) malloc (sizeof(Node));
    n->val = v;
    n->left = NULL; n->right = NULL;
    return n;
}

Node* bst_insert (Node* root, int key) {
    if (!root) return make (key);
    if (root->val > key) {
        root->left = bst_insert (root->left, key);
    }
    else if (root->val < key) {
        root->right = bst_insert (root->right, key);
    }
    return root;
}

Node* bst_search (Node* root, int key) {
    if (!root) return NULL;
    if (root->val == key) return root;
    if (root->val > key) return bst_search (root->left, key);
    if (root->val < key) return bst_search (root->right, key);
}

Node* bst_min (Node* root) {
    if (!root) return NULL;
    while (root->left) {
        root = root->left;
    }
    return root;
}

Node* bst_max (Node* root) {
    if (!root) return NULL;
    while (root->right) {
        root = root->right;
    }
    return root;
}

Node* bst_delete (Node* root, int key) {
    if (!root) return NULL;
    if (root->val > key) root->left = bst_delete (root->left, key);
    else if (root->val < key) root->right = bst_delete (root->right, key);
    else {
        if (!root->left && !root->right) {
            free (root);
            return NULL;
        }
        else if (!root->left) {
            free (root);
            return root->right;
        } else if (!root->right) {
            free (root);
            return root->left;
        } else {
            Node* m =  bst_min (root->right);
            root->val = m->val;
            root->right = bst_delete (root->right, m->val);
        }
    }
    return root;
}

int res[32];
int cnt;

void visit (int v) { res[cnt++] = v;}

void inorder (Node* n) {
    if (!n) return;
    inorder (n->left);
    visit (n->val);
    inorder (n->right);
}

void free_tree (Node* n) {
    if (!n) return;
    free_tree (n->left);
    free_tree (n->right);
    free (n);
}
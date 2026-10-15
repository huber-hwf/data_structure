#include<iostream>
#include<new>
#include<cstdlib>
using namespace std;

typedef struct AVLNode{
    int key;
    int height;
    AVLNode* left;
    AVLNode* right;
    AVLNode(int _key){
        key=_key;
        height=1;
        left=NULL;
        right=NULL;
    }
};

typedef struct AVLTree{
    AVLNode* root;
    int size;
    AVLTree(int _size, int key){
        root=new AVLNode(key);
        size=_size;
    }
};

int h(const AVLNode* n){
    return n?n->height:0;
}

void update_height(AVLNode* n){
    n->height=1+max(h(n->left), h(n->right));
}

int bf(AVLNode* n){
    return n?h(n->left)-h(n->right):0;
}

AVLNode* node_new(int key){
    AVLNode* n=new AVLNode(key);
    if(!n) return NULL;
    return n;
}

AVLNode* rotate_right(AVLNode* y){
    AVLNode* x=y->left;
    AVLNode* T2=x->right;
    x->right=y;
    y->left=T2;
    update_height(y);
    update_height(x);
    return x;
}

AVLNode* rotate_left(AVLNode* x){
    AVLNode* y=x->right;
    AVLNode* T2=y->left;
    y->left=x;
    x->right=T2;
    update_height(y);
    update_height(x);
    return y;
}

AVLNode* rebalance(AVLNode* n){
    update_height(n);
    int balance=bf(n);
    if(balance>1){
        if(bf(n->left)<0)
    }
}
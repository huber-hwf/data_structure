#include<iostream>
#include<cstdlib>
#include<new>
using namespace std;

typedef enum{P=1, I=2, L=3} order;

typedef struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int _val, Node* _left=NULL, Node* _right=NULL){
        val=_val;
        left=_left;
        right=_right;
    }
};

Node* Node_Make(int val){
    Node* n=new Node(val);
    if(!n) return NULL;
    return n;
}

void BT_Free(Node* root){
    if(!root) return;
    BT_Free(root->left);
    BT_Free(root->right);
    delete(root);
    root=NULL;
}

Node* BT_Builed(void){
    Node* n6=Node_Make(6);
    Node* n5=Node_Make(5);
    Node* n4=Node_Make(4);
    Node* n3=Node_Make(3); n3->right=n6;
    Node* n2=Node_Make(2); n2->left=n4; n2->right=n5;
    Node* n1=Node_Make(1); n1->left=n2; n1->right=n3;
    return n1;
}

int res[16];
int cnt;
void visit(int v){res[cnt++]=v;}

void BT_Traverse(Node* root, order op){
    if(!root) return;
    if(op==P){visit(root->val); BT_Traverse(root->left, op); BT_Traverse(root->right, op);}
    if(op==I){BT_Traverse(root->left, op); visit(root->val); BT_Traverse(root->right, op);}
    if(op==L){BT_Traverse(root->left, op); BT_Traverse(root->right, op); visit(root->val);}
}

typedef struct Stack{
    Node** data;
    int top;
    int cap;
    Stack(int _cap){
        data=new Node*[_cap];
        top=0;
        cap=_cap;
    }
};

Stack* Stack_Make(int cap){
    Stack* stk=new Stack(cap);
    if(!stk) return NULL;
    return stk;
}

void Stack_Push(Stack* stk, Node* n){
    stk->data[(stk->top)++]=n;
}

bool Stack_Isempty(Stack* stk){
    return stk->top==0;
}

bool Stack_Pop(Stack* stk, Node** out){
    if(!stk->top) return false;
    *out = stk->data[stk->top--];
    return true;
}

void Stack_Free(Stack* stk){
    if(stk) delete(stk->data);
    delete(stk);
    stk=NULL;
}

void pre_iter(Node* root){
    Stack* stk=Stack_Make(16);
    if(!stk) return;
    if(root) Stack_Push(stk, root);
    else return;
    while(!Stack_Isempty(stk)){
        Node** n;
        Stack_Pop(stk, n);
        visit((*n)->val);
        if((*n)->right) Stack_Push(stk, (*n)->right);
        if((*n)->left) Stack_Push(stk, (*n)->left);
    }
    Stack_Free(stk);
}

typedef struct Queue{
    Node** data;
    int head, tail;
    int cap;
    Queue(int _cap){
        data=new Node*[_cap];
        head=0;
        tail=0;
        cap=_cap;
    }
};

Queue* Queue_New(int cap){
    Queue* q=new Queue(cap);
    if(!q) return NULL;
    return q;
}

bool Queue_Isempty(Queue* q){
    return q->tail==q->head;
}

Queue* Queue_Push(Queue* q, Node* n){
    q->data[q->tail]=n;
    q->tail=(++(q->tail)%q->cap);
}

bool Queue_Pop(Queue* q, Node* &out){
    if(q->head==q->tail) return false;
    out=q->data[q->head++];
    q->head%=q->cap;
}

void Queue_Free(Queue* q){
    if(q) delete(q->data);
    delete(q);
    q=NULL;
}

bool level_order(Node* root){
    Queue* q=Queue_New(16);
    if(!q) return false;
    if(root) Queue_Push(q, root);
    else return false;
    while(!Queue_Isempty(q)){
        Node* n;
        Queue_Pop(q, n);
        visit(n->val);
        if(n->left) Queue_Push(q, n->left);
        if(n->right) Queue_Push(q, n->right);
    }
    delete(q);
    return true;
}
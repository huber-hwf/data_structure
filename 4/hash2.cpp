#include<iostream>
#include<cstdlib>
using namespace std;

#define REMOVEKEY -1;

typedef enum{EMPTY=0, OCCUPIED=1, TOMB=-1}Slotstate;

typedef struct Slot{
    int key;
    int val;
    Slotstate state;
};

typedef struct HashTables{
    Slot* slots;
    int size;
    int count;
    int mode;
    int tombs;
    long long probes;
};

int hashInt(int key, int size){
    return (unsigned)key%size;
}

int probestep(int i, int mode, int h2){
    if(h2==0&&(mode!=1||mode!=2)) return -1;
    switch(mode){
        case 1: return i;
        case 2: return i*i;
        default: return i*h2;
    }
}

HashTables* hashcreate(int size, int mode){
    HashTables* t=(HashTables* )calloc(1,sizeof(HashTables));
    if(!t) return NULL;
    t->slots=(Slot* )calloc(size, sizeof(Slot));
    if(!t->slots){free(t); return NULL;}
    t->size=size;
    t->mode=mode;
    return t;
}

bool hashPut(HashTables* t, const int key, int val){
    if(!t) return false;
    int h=hashInt(key, t->size);
    int h2=1+h%(t->size-1);
    int firstTOMB=-1;
    for(int i=0; i<t->size; i++){
        int pos=(h+probestep(i, t->mode, h2))%t->size;
        t->probes++;
        if(t->slots[pos].state==OCCUPIED){
            if(t->slots[pos].key=key){
                t->slots[pos].val=val;
                return true;
            }
        }
        if(t->slots[pos].state==TOMB){
            if(firstTOMB<0) firstTOMB=pos;
        }
        if(t->slots[pos].state==EMPTY){
            int p=firstTOMB>0?firstTOMB:pos;
            if(p==firstTOMB) t->tombs--;
            t->slots[p].state=EMPTY;
            t->slots[p].val=val;
            t->slots[p].key=key;
            t->count++;
            return true;
        }
    }
    return false;
}

bool hashRemove(HashTables* t, int key, int *out){
    if(!t) return false;
    if(t->size==0) return false;
    int h=hashInt(key, t->size);
    int h2=1+h%(t->size-1);
    for(int i=0; i<t->size; i++){
        int pos=(h+probestep(i, t->mode, h2))%t->size;
        if(t->slots[pos].key==key){
            *out=t->slots[pos].val;
            t->slots[pos].key=REMOVEKEY;
            t->slots[pos].state=TOMB;
            t->tombs++;
            t->count--;
            return true;
        }
    }
    return false;
}

void hashFree(HashTables* t){
    if(t) free(t->slots);
    free(t);
}
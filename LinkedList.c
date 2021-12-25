#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[], int n){
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p){
    while(p != NULL){
        printf("  %d  ",p->data);
        p=p->next;
    }

}

void RDisplay(struct Node *p){
    if(p != NULL){
        printf("%d\n",p->data);
        RDisplay(p->next);
    }
}

int RCount(struct Node *p){
    if(p != NULL) return RCount(p->next) + 1;
    else return 0;
}

int RSum(struct Node *p){
    if(p != NULL) return RSum(p->next) + p->data;
    else return 0;
}

int RMax(struct Node *p){
    int x=0;
    if(p==0) return INT_MIN;
    
    x = RMax(p->next);
    if(x > p->data) return x;
    return p->data;
}

struct Node * LSearch(struct Node *p, int key){
    struct Node *q;
    q=p;
    while(p != NULL){
        if(key == p->data){
            printf("%d\n",q->data);
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

void Insert(struct Node *p, int index, int x){
    if(index < 0 || index > RCount(p)) return;
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if(index == 0){
        t->next = first;
        first = t;
    }else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main(){
    struct Node *temp;
    Insert(first,0,10);
    Insert(first,1,20);
    Insert(first,2,30);
    Insert(first,1,50);
    Display(first); 
}

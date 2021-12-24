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
        printf("%d",p->data);
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

int main(){
    int A[] = {3,5,7,10,15,50,8,12,20};

    Create(A, 9);
    printf("Sum is:  %d\n", RSum(first));
    printf("Count is:   %d\n",RCount(first));
    printf("Max Element:   %d\n",RMax(first));
    
}

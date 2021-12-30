#include <iostream>
using namespace std;

class Node{
    public:
        Node *prev;
        int data;
        Node *next;
};

class DoublyLinkedList{
    private:
        Node *head;
    public:
        DoublyLinkedList(int A[], int n);
        ~DoublyLinkedList();
        void Display();
        int Length();
        void Insert(int index, int x);
        int Delete(int index);
        void Reverse();
};

DoublyLinkedList::DoublyLinkedList(int *A, int n){
    Node *t, *last;

    head = new Node;
    head->prev = NULL;
    head->data = A[0];
    head->next = NULL;

    last = head;

    for(int i=1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void DoublyLinkedList::Display(){
    Node *p = head;
    while(p){
        cout<<p->data<<"  ";
        p=p->next;
    }
    cout<<endl;
}

DoublyLinkedList::~DoublyLinkedList(){
    Node *p=head;
    while(p){
        head=p->next;
        delete p;
        p=head;
    }
}

int DoublyLinkedList::Length(){
    int len = 0;
    Node *p = head;

    while(p){
        len++;
        p=p->next;
    }
    return len;
}

void DoublyLinkedList::Insert(int index, int x){
    Node *t, *p = head;

    if(index<0 || index>Length()) return;

    if(index == 0){
        t = new Node;
        t->data = x;
        t->prev = head->prev;
        head->prev = t;
        t->next = head;
        head = t;
    }else{
        for(int i=0;i<index-1;i++) p=p->next;
        t = new Node;
        t->data = x;

        t->prev = p;
        t->next = p->next;
        if(p->next) p->next->prev=t;
        p->next = t;
    }
}

int DoublyLinkedList::Delete(int index){
    Node *q, *p = head;
    int x=-1;
    if(index<1 || index>Length()) return -1;

    if(index == 1){
        head = head->next;
        if(head) head->prev = NULL;
        
        x=p->data;
        delete p;
    }else{
        for(int i=0;i<index-1;i++) p=p->next;
        
        p->prev->next = p->next;
        if(p->next) p->next->prev = p->prev;
        
        x=p->data;
        delete p;
    }
    return x;
}

void DoublyLinkedList::Reverse(){
    Node *t, *p = head;

    while(p){
        t=p->next;
        p->next = p->prev;
        p->prev = t;
        p=p->prev;
        if(p && p->next == NULL) head=p;
    }
}

int main(){
    int A[] = {10,20,30,40,50};
    DoublyLinkedList DLL(A, 5);
    DLL.Reverse();
    cout<<"Length:  "<<DLL.Length()<<endl;
    DLL.Display();
    return 0;    
}



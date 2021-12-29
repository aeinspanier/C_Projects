#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class CircularLinkedList{
    private:
        Node *head;
    public:
        CircularLinkedList(int A[], int n);
        void Display();
        void recursiveDisplay(Node *p);
        Node *getHead(){return head;}
        ~CircularLinkedList();
        void Insert(int index, int x);
        int Length();
        int Delete(int index);
};

CircularLinkedList::CircularLinkedList(int *A, int n){
    Node *t;
    Node *tail;

    head = new Node;
    head->data = A[0];
    head->next = head;
    tail=head;

    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next = tail->next;
        tail->next = t;
        tail=t;
    }
}

void CircularLinkedList::Display(){
    Node *p = head;
    do{
        cout<<p->data << " -> " << flush;
        p=p->next;
    }while(p != head);
    cout<<endl;
}

void CircularLinkedList::recursiveDisplay(Node *p){
    static int flag=0;
    if(p!=head || flag == 0){
        flag=1;
        cout<<p->data << " -> " <<flush;
        recursiveDisplay(p->next);
    }
    flag=0;
}

CircularLinkedList::~CircularLinkedList(){
    Node *p=head;
    while(p->next != head){
        p=p->next;
    }

    while(p != head){
        p->next = head->next;
        delete head;
        head = p->next;
    }
    if(p==head){
        delete head;
        head = nullptr;
    }
}

int CircularLinkedList::Length(){
    int len = 0;
    Node *p = head;

    do{
        len++;
        p=p->next;
    }while(p != head);
    return len;
}

void CircularLinkedList::Insert(int index, int x){
    Node *t, *p=head;

    if(index<0 || index>Length()) return;

    if(index == 0){
        t = new Node;
        t->data = x;
        if(head == NULL){
            head = t;
            head->next = head;
        }else{
            while(p->next != head){
                p=p->next;
            }
            p->next=t;
            t->next = head;
            head = t;
        }
    }else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t= new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int CircularLinkedList::Delete(int index){
    Node *q, *p = head;
    int x;

    if(index<0 || index > Length()) return -1;

    if(index == 1){
        while(p->next != head) p=p->next;
        x = head->data;
        if(head == p){
            delete head;
            head = nullptr;
        }else{
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }else{
        for(int i=0;i<index-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next = q->next;
        x=q->data;
        delete q;
    }
    return x;
}

int main(){
    int A[]={1,3,5,7,9};

    CircularLinkedList cl(A,sizeof(A)/sizeof(A[0]));
    cout<<cl.Delete(2)<<endl;
    cl.Display();

    Node *h = cl.getHead();
    cl.recursiveDisplay(h);

    return 0;
}






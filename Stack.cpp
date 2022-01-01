#include <iostream>

using namespace std;

class Node{
    public:
        char data;
        Node *next;
};

class Stack{
    private:
        Node *top;
    public:
        Stack();
        ~Stack();
        void Display();
        void Push(int x);
        int IsFull();
        int IsEmpty();
        int Pop();
        int Peek(int index);
        int StackTop();
        bool IsBalanced(char *exp);
};

Stack::Stack(){
    top = nullptr;
}

Stack::~Stack(){
    Node *p = top;
    while(p){
        top = p->next;
        delete p;
        p=top;
    }
}

void Stack::Display(){
    Node *p = top;
    while(p){
        cout<<p->data<<" | "<<flush;
        p=p->next;
    }
    cout<<endl;
}

int Stack::IsFull(){
    Node *t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}

void Stack::Push(int x){
    Node *t = new Node;
    if(t == nullptr) cout<<"Stack Overflow"<<endl;
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::IsEmpty(){
    return top ? 0 : 1;
}

int Stack::Pop(){
    int x = -1;
    Node *p;
    if(IsEmpty()){
        cout<<"Stack underflow"<<endl;
    }else{
        p=top;
        x = top->data;
        top = top->next;
        delete p;
    }
    return x;
}

int Stack::Peek(int index){
    int x=-1;
    if(IsEmpty()){
        cout<<"function Peek stack empty"<<endl;  
        return -1;
    }
    else{
        Node *p=top;
        for(int i=0; p && i<index-1;i++){
            p=p->next;
        }
        if(p){
            x = p->data;
        }
    }
    return x;
}

int Stack::StackTop(){
    int x = -1;
    if(IsEmpty()) cout<<"Empty"<<endl;
    else x = top->data;
    return x;
}

bool Stack::IsBalanced(char *exp){
    for(int i=0; exp[i] != '\0';i++){
        if(exp[i] == '('){
            Push(exp[i]);
        }
        else if(exp[i] == ')'){
            if(IsEmpty()) return false;
            Pop();
        }
    }
    return IsEmpty() ? true : false;
}

int main(){
    Stack stk;
    char E[] = "((a+b)*(c-d))(";
    cout << stk.IsBalanced(E) << endl;
    
    return 0;
}


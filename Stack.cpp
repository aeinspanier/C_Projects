#include <iostream>

using namespace std;

class Stack{
    private:
        int size;
        int top;
        int *S;
    public:
        Stack(int size);
        ~Stack();
        void Display();
        void Push(int x);
        int IsFull();
        int IsEmpty();
        int Pop();
        int Peek(int index);
        int StackTop();
};

Stack::Stack(int size){
    this->size=size;
    top = -1;
    S = new int[size];
}

Stack::~Stack(){
    delete[] S;
}

void Stack::Display(){
    for(int i=top;i>=0;i--){
        cout<<S[i]<<" | "<<flush;
    }
    cout<<endl;
}

int Stack::IsFull(){
    if(top==size-1) return 1;
    else return 0;
}

void Stack::Push(int x){
    if(IsFull()) cout<<"Stack Overflow"<<endl;
    else{
        top++;
        S[top] = x;
    }
}

int Stack::IsEmpty(){
    if(top==-1) return 1;
    else return 0;
}

int Stack::Pop(){
    int x = -1;
    if(IsEmpty()){
        cout<<"Stack underflow"<<endl;
    }else{
        x = S[top];
        top--;
    }
    return x;
}

int Stack::Peek(int index){
    int x=-1;
    int stackPos = top-index+1;

    if(stackPos < 0 || stackPos==size) cout<<"Invalid position"<<endl;
    else{
        x = S[stackPos];
    }
    return x;
}

int Stack::StackTop(){
    int x = -1;
    if(IsEmpty()) cout<<"Empty"<<endl;
    else x = S[top];
    return x;
}

int main(){
    int A[] = {1,3,5,7,9};
    int len = sizeof(A)/sizeof(A[0]);
    Stack stck(len);
    
    for(int i = 0; i<len;i++){
       stck.Push(A[i]);
    }
    
    stck.Push(11);

    stck.Display();

    cout<<stck.Peek(1)<<endl;

    cout<<stck.Pop()<<endl;

    stck.Display();

    return 0;
}


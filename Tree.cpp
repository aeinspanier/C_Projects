#include <iostream>
using namespace std;

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class Queue{
    private:
        int size;
        int front;
        int rear;
        Node **Q;
    public:
        Queue(int size);
        ~Queue();
        bool isEmpty();
        bool isFull();
        void enqueue(Node *x);
        Node* dequeue();
};

Queue::Queue(int size){
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node *[size];
}

Queue::~Queue(){
    delete [] Q;
}

bool Queue::isEmpty(){
    if(front == rear) return true;
    return false;
}

bool Queue::isFull(){
    if(rear == size-1) return true;
    return false;
}

void Queue::enqueue(Node *x){
    if(isFull()) cout<<"enqueue: Queue full!"<<endl;
    else{
        rear++;
        Q[rear] = x;
    }
}

Node * Queue::dequeue(){
    Node *x = nullptr;
    if(isEmpty()) cout<<"dequeue: Queue empty!"<<endl;
    else{
        front++;
        x = Q[front];
    }
    return x;
}

class Tree{
    private:
        Node *root;
    public:
        Tree(){root=NULL;}
        void CreateTree();
        void Preorder(){Preorder(root);}
        void Preorder(Node *p);
        void Postorder(){Postorder(root);}
        void Postorder(Node *p);
        void Inorder(){Inorder(root);}
        void Inorder(Node *p);
        void Levelorder(){Levelorder(root);}
        void Levelorder(Node *p);
        int Height(){return Height(root);}
        int Height(Node *root);
};

void Tree::CreateTree(){
    Node *p, *t=NULL;
    int x;
    Queue q(100);

    cout<<"enter root value: "<<flush;
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.enqueue(root);

    while(! q.isEmpty()){
        p = q.dequeue();

        cout << "enter left child value of "<<p->data<< ": " <<flush;
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }

        cout << "enter right child value of "<<p->data<< ": " <<flush;
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p){
    if(p){
        cout << p->data<< ", "<<flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<", "<<flush;
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<", "<<flush;
    }
}

void Tree::Levelorder(Node *p){
    Queue q(100);
    cout<<p->data<<" "<<flush;

    q.enqueue(p);

    while(!q.isEmpty()){
        p = q.dequeue();
        if(p->lchild){
            cout<<p->lchild->data<<" "<<flush;
            q.enqueue(p->lchild);
        }
        if(p->rchild){
            cout<<p->rchild->data<<" "<<flush;
            q.enqueue(p->rchild);
        }
    }
}

int Tree::Height(Node *root){
    int x=0,y=0;
    if(root==0) return 0;
    x=Height(root->lchild);
    y=Height(root->rchild);
    if(x>y) return x+1;
    else return y+1;
}

int main() {
    Tree t;
    t.CreateTree();

    t.Preorder();
    cout<<endl;

    t.Inorder();
    cout<<endl;

    t.Postorder();
    cout<<endl;

    t.Levelorder();
    cout<<endl;

    cout<<"Height "<<t.Height()<<endl;
    
    return 0;
}

#include<iostream>
//#include<stdio.h>
//#include<stdlib.h>
using namespace std;

struct Rectangle{
    int length;
    int breadth;


void initialize(int l, int b)
{
    length = l;
    breadth = b;
}

int area()
{
    return length*breadth;
}
};

int main()
{
    Rectangle r;
    int l,b;
    printf("enter length & Breadth");
    cin>>l>>b;

    r.initialize(l,b);

    cout<<"area is  "<<r.area()<<endl;
    return 0;
}


#include "sirArray.cpp"
#include<iostream>
using namespace std;
class stack:public Array
{
    public:
    stack(int cap);
    void push(int);
    int peek();
    void pop();
    ~stack();
    virtual int isStackOverflow();
    virtual int isStackUnderflow();

};
int stack::isStackUnderflow()
{
    return isEmpty();
}
int stack::isStackOverflow()
{
    return isFull();
}
stack::~stack()
{
}
void stack::pop()
{
    if(isEmpty())
        cout<<"Stack Overflow"<<endl;
    else
        del((count()-1));
}
int stack::peek()
{
    if(!isEmpty())
        return get(count()-1);
    return 0;
}
void stack::push(int data)
{
    if(isFull())
        cout<<"stack overflow"<<endl;
    else
        append(data);
}
stack::stack(int cap):Array(cap)
{}
int main()
{
    stack s(5);
    s.push(5);
    s.push(15);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    
    return 0;
}
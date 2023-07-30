#include "sll.cpp"
#include<iostream>
using namespace std;

class Stack:private sll
{
    private:
    node *top;
    public:
    Stack();
    void push(int data);
    int peek();
    void pop();
    ~Stack();
};
Stack::~Stack(){};
void Stack::pop()
{
    if(getStart())
        deleteEnd();
    else
        cout<<"Stack is Empty"<<endl;
}
int Stack::peek()
{
    if(getStart())
    return top->item;
    return -1;
}
void Stack::push(int data)
{
    if(getStart())
    {
        insertEnd(data);
        top=top->next;
        
    }
    else
    {
        insertEnd(data);
        top=search(data);
    }
       
}
Stack::Stack():sll()
{
    top=NULL;
}

int main()
{
    return 0;
}
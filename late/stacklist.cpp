#include<iostream>
using namespace std;

class node
{
    public:
    int item;
    node *next;
};
class stack
{   
    private:
    node *top;
    public:
    stack();
    void push(int data);
    int peek();
    void pop();
    ~stack();
};
stack::~stack()
{
    while(top)
    {
        pop();
    }
}
void stack::pop()
{
    if(top)
    {
        node *n=top;
        top=top->next;
        delete n;
    }


}
int stack::peek()
{
    if(top)
        return top->item;
    cout<<"Stack is Empty"<<endl;
    return -1;
}
void stack::push(int data)
{
    node *n=new node;
    n->item=data;
    n->next=top;
    top=n;
    
}
stack::stack()
{top=NULL;}
int main()
{

    return 0;
}
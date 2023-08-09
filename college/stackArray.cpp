#include "array.cpp"
#include<iostream>
using namespace std;

class Stack:private Array
{
    int *top;
    public:
    Stack(int data);
    void push(int data);
    int peek(); 
    void pop();
    ~Stack();
    virtual int isStackOverflow();
    virtual int isStackUnderflow(); 
    Stack reverseStack();
    int getminimum();
    void displayStack();
};
void Stack::displayStack()
{
    //it will display from down to up . means it will show first the element which get out last
    displayArray();
}
int Stack::getminimum()
{
    int min=getele(0),i=0;
    while(i-1!=getCapacity())
    {
        if(min>getele(i))
            min=getele(i);
    }
    return min;
}
Stack Stack::reverseStack()
{
    Stack s1(getCapacity());
    while(!isEmpty())
    {
        s1.push(peek());
        pop();
    }
    return s1;
}
int Stack::isStackUnderflow()
{
    return isEmpty();
}
int Stack::isStackOverflow()
{
    return isFull();
}
Stack::~Stack(){}
void Stack::pop()
{
    deleteEle(count()-1);
}
int Stack::peek()
{
    return getele(count()-1);
}
void Stack::push(int data)
{
    append(data);
}
Stack::Stack(int data):Array(data)
{}
int main()
{
    Stack s(5);
    s.push(11);
    s.displayStack();
    s.push(15);
    s.push(25);
    s.push(35);
    s.push(45);
    s.displayStack();
    s.pop();
    s.displayStack();
    cout<<s.peek()<<endl;
    cout<<endl;
    s.displayStack();
    cout<<s.isStackOverflow()<<endl;
    cout<<endl;
    cout<<s.isStackUnderflow()<<endl;
    cout<<endl;
    Stack p=s.reverseStack();
    p.displayStack();
    return 0;
}
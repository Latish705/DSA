#include "DynArray.cpp"
#include<iostream>
using namespace std;

class Stack:private DynArray
{
    public:
    Stack(int data);
    void push(int data);
    int peek();
    void pop();
    bool isStackOverFlow();
    bool isStackUnderFlow();
    Stack reverseStack();
    int getMinimum();
};
// int Stack::getMinimum()
// {
//     int min;
//     while()

// }
Stack Stack::reverseStack()
{
    Stack p(getCapacity());
    while(!isEmpty)
    {
        p.push(peek());
        pop();
    }
}
bool Stack::isStackUnderFlow()
{
    return isEmpty();
}
bool Stack::isStackOverFlow()
{
    return isFull();
}
void Stack::pop()
{
    deleteEle(getCount()-1);
}
int Stack::peek()
{
    return getAtIndex(getCount()-1);
}
void Stack::push(int data)
{
    DynArray::append(data);
}
Stack::Stack(int data):DynArray(data){}

#include "DynArray.cpp"
#include<iostream>
using namespace std;

class Stack:private DynArray
{
    public:
    Stack(int data);
    void push(int data);
    
};
void Stack::push(int data)
{
    DynArray::append(data);
}
Stack::Stack(int data):DynArray(data){}
int main()
{

    return 0;
}
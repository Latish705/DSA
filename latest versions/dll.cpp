#include<iostream>
using namespace std;


class node{
    public:
    node *prev;
    int item;
    node *next;
};
class dll
{
    private:
    node *start;
    public:
    dll();
    void insertStart(int data);
};
void dll::insertStart(int data)
{
    if(start)
    {
        node *n=new node;
        n->item=data;
        n->next=start;
        n
    }
}
dll::dll()
{
    start=NULL;
}

int main()
{
    
    return 0;
}
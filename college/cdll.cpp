#include<iostream>
using namespace std;

class node
{
    public:
        int item;
        node *prev;
        node *next;
};
class cdll
{
    private:
        node *start;
    public:
        cdll();
        void insertStart(int data);
        void insertEnd(int data);
        node* search(int data);
        void insertSpecified(node *address,int data);
        void deleteStart();
        void deleteEnd();
        void deleteSpecified(node *address);
        ~cdll();
};
cdll::~cdll()
{
    while(start)
        deleteStart;
}
void cdll::deleteSpecified(node *address)
{
    address->prev->next=address->next;
    address->next->prev=address->prev;
    delete address;
}
void cdll::deleteEnd()
{
    if(start)
    {
        node *n=start->prev;
        start->prev=start->prev->prev;
        start->prev->prev->next=start->prev->next;
        delete n;
    }
    else
    {
        cout<<"List is Empty"<<endl;
    }
}
void cdll::deleteStart()
{
    if(start)
    {
        node *n=start;
        start->next->prev=start->prev;
        start->prev->next=start->next;
        start=start->next;
        delete n;
    }
    else
    {
        cout<<"Empty List"<<endl;
    }
}
void cdll::insertSpecified(node *address,int data)
{
    node *n=new node;
    n->next=address->next;
    n->prev=address;
    n->item=data;
    n->next->prev=n;
    address->next=n;
}
node* cdll::search(int data)
{
    if(start)
    {
        node *t;
        while(t->item!=data)
            t=t->next;
        return t;
    }
    return NULL;
}
void cdll::insertEnd(int data)
{
    node *n=new node;
    if(start)
    {
        n->item=data;
        n->next=start;
        n->prev=start->prev;
        start->prev=n;
        n->prev->next=n;
    }
    else
    {
        n->item=data;
        n->next=n;
        n->prev=n;
    }
}
void cdll::insertStart(int data)
{   
    node *n=new node;
    if(start)
    {
        n->next=start;
        n->prev=start->prev;
        n->item=data;
        n->prev->next=n;
        start->prev=n;
        start=n;
    }
    else
    {
        n->item=data;
        n->next=n;
        n->prev=n;
    }
}
cdll::cdll()
{
    start=NULL;
}
int main()
{

    return 0;
}
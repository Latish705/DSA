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
    void insertEnd(int data);
    node* search(int data);
    void insert(node *address,int data);
    void deleteStart();
    void deleteEnd();
    void deleteSpecific(node *address);
    ~dll();
};
dll::~dll()
{
    while(start)
        delete start;
}
void dll::deleteSpecific(node *address)
{
    address->next->prev=address->prev;
    address->prev->next=address->next;
    delete address;
}
void dll::deleteEnd()
{
    if(start)
    {
        node *n=start;
        node *t;
        while(n->next->next)
            n=n->next;
        t=n->next;
        n->next=NULL;
        delete t;
    }
    else
        cout<<"List is Empty"<<endl;
}
void dll::deleteStart()
{
    if(start)
    {
        node *n=start;
        start=start->next;
        start->prev=NULL;
        delete n;
    }
    else
        cout<<"List is Empty"<<endl;
}
void dll::insert(node *address,int data)
{
    node *n=new node;
    n->prev=address;
    n->item=data;
    n->next=address->next;
    address->next=n;
    n->next->prev=n;
}
node* dll::search(int data)
{
    if(start)
    {
        node *n=start;
        while(n->item!=data)
            n=n->next;
        return n;
    }
    cout<<"List is Empty"<<endl;
    return NULL;
}
void dll::insertEnd(int data)
{
    node *n=new node;
    if(start)
    {
        n->item=data;
        node *t=start;
        while(t->next)
            t=t->next;
        n->next=NULL;
        n->prev=t;
        t->next=n;
    }
    else
    {
        n->item=data;
        n->next=NULL;
        n->prev=NULL; 
    }
}
void dll::insertStart(int data)
{
    node *n=new node;
    if(start)
    {
        n->item=data;
        n->next=start;
        n->prev=NULL;
        start->next->prev=n;
        start=n;
    }
    else
    {
        n->item=data;
        n->next=NULL;
        n->prev=NULL;    
    }
}
dll::dll()
{
    start=NULL;
}

// int main()
// {
    
//     return 0;
// }
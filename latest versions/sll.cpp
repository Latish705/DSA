#include<iostream>
using namespace std;


class node{
    public:
    int item;
    node *next;
};
class sll{
    private:
    node *start;
    public:
    sll();
    void insertStart(int data);
    void insertEnd(int data);
    node* search(int data);
    void insert(node *address,int data);
    void deleteStart();
    void deleteEnd();
    void deleteSpecific(node *address);
    ~sll();
};
sll::~sll()
{
    while(start)
        deleteStart();
}
void sll::deleteSpecific(node *address)
{
    node *t=start;
    while(t->next=address)
        t=t->next;
    t->next=address->next;
    delete address;
}
void sll::deleteEnd()
{
    if(start)
    {
        node *t=start;
        while(t->next->next)
            t=t->next;
        node *n=t->next;
        t->next=n->next;
        delete n;
    }
    cout<<"List is Empty"<<endl;
}
void sll::deleteStart()
{
    if(start)
    {
        node *n;
        n=start;
        start=start->next;
        delete n;
    }
    cout<<"List is Empty"<<endl;
}
void sll::insert(node *address,int data)
{
    //we insert after that address;
    node *n=new node;
    n->item=data;
    n->next=address->next;
    address->next=n;
}
node* sll::search(int data)
{
    if(start)
    {
        node *n;
        n=start;
        while(n->item!=data)
        n=n->next;
        return n;
    }
    cout<<"List Empty"<<endl;
    return NULL;
}
void sll::insertEnd(int data)
{
    node *n=new node;
    node *t;
    if(start)
    {
        n->next=NULL;
        n->item=data;
        t=start;
        while(t->next)
            t=t->next;
        t->next=n;
    }
    else
    {
        n->item=data;
        n->next=NULL;
        start=n;
    }
}
void sll::insertStart(int data)
{
    node *n=new node;
    if(start)
    {
        n->next=start;
        n->item=data;
        start=n;
    }
    else
    {
        n->item=data;
        n->next=NULL;
        start=n;
    }
}
sll::sll()
{
    start=NULL;
}
int main()
{
    return 0;
}
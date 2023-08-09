#include<iostream>
using namespace std;

class node
{
    public:
    int item;
    node *next;
};
class csll
{
    private:
        node *last;
    public:
        csll();
        void insertStart(int data);
        void insertEnd(int data);
        node* search(int data);
        void insertSpecified(node *address,int data);
        void deleteStart();
        void deleteEnd();
        void deleteSpecified(node *address);
        ~csll();
};
csll::csll()
{
    while(last)
        deleteStart();
}
void csll::deleteSpecified(node *address)
{
    node *t=last;
    while(t->next!=address)
        t=t->next;
    t->next=address->next;
    delete address;
}
void csll::deleteEnd()
{
    if(last)
    {
        node *t;
        node *n;
        while(t->next!=last)
            t=t->next;
        n=last;
        t->next=last->next;
        last=t;
        delete n;
    }
    else
        cout<<"List is empty"<<endl;

}
void csll::deleteStart()
{
    if(last)
    {
        node *n=last->next;
        last->next=last->next->next;
        delete n;
    }
    else
        cout<<"List is empty"<<endl;
}
void csll::insertSpecified(node *address,int data)
{
    node *n=new node;
    n->next=address->next;
    n->item=data;
    address->next=n;
}
node* csll::search(int data)
{
    node *t=last;
    node *n=last;
    while(t->item!=data)
    {
        if(t->next==last)
            break;
        if(t->item==data)
            return t;
    }
}
void csll::insertEnd(int data)
{
    node *n=new node;
    if(last)
    {
        n->next=last->next;
        n->item=data;
        last=n;
    }
    else
    {
        last=n;
        n->next=n;
        n->item=data;
    }
}
void csll::insertStart(int data)
{
    node *n=new node;
    if(last)
    {
        n->next=last->next;
        n->item=data;
    }
    else
    {
        last=n;
        n->next=n;
        n->item=data;
    }
}
csll::csll()
{
    last=NULL;
}
int main()
{

    return 0;
}
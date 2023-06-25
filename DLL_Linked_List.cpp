#include<iostream>
using namespace std;

class node
{
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
        void displayList();
        void insertLast(int data);
        node* SearchNodeWithData(int data);
};
node* dll::SearchNodeWithData(int data)
{
    node *t;
    t=start;
    while(t!=NULL)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}   


void dll::insertLast(int data)
{
    node *n=new node;
    if(start)
    {
        node *t;
        t=start;
        int i;
        for(i=1;t->next;i++)
        t=t->next;
        n->prev=t;
        t->next=n;
        n->item=data;
        n->next=NULL;
        
    }
    else
    {
       n->next=start;
        n->prev=NULL;
        start->prev=n;
        n->item=data;
        start=n;

    }
}
void dll::insertStart(int data)
{
    node *n=new node;
    if(start)
    {
        n->next=start;
        n->prev=NULL;
        start->prev=n;
        n->item=data;
        start=n;
    }
    else
    {
        start=n;
        n->next=NULL;
        n->prev=NULL;
        n->item=data;
    }
}
void dll::displayList()
{
    int i;
    node *t;
    t=start;
    for(i=1;t;i++)
    {
        cout<<"node "<<i<<" = "<<t->item<<endl;
        t=t->next;
    }
}

dll::dll()
{
    start=NULL;
}

int main()
{
    dll l1;
    l1.insertStart(53);
    l1.displayList();
    l1.insertStart(43);
    l1.displayList();
    l1.insertLast(51);
    l1.displayList();

    return 0;
}
q
#include<iostream>
using namespace std;

class node
{
    public:
    node *prev;
    node *next;
    int item;
};
class dll
{
    private:
    node *start;
    public:
        dll();
        void insertStart(int data);
        void insertLast(int data);
        void displaylist();
        node* search(int data);
        void insertAtNode(node *t,int data);
        void deletefirst();
        void deletelast();
        void deleteAtNode(node*);
        ~dll();
};
void dll::insertAtNode(node *t,int data)
{   
    if(start)
    {
        node *n=new node;
        n->prev=t->next->prev;
        n->next=t->next;
        n->item=data;
        t->next=n;
        t->next->prev=n;
    }
}
dll::~dll()
{
    while(start)
        deletefirst();
}
void dll::deleteAtNode(node *n)
{
    if(n->next!=NULL)
    {
        n->prev->next=n->next;
        n->next->prev=n->prev;
        delete n;
    }
}
void dll::deletelast()
{
    node *t;
    t=start;
    while(t->next->next)
        t=t->next;
    node *n=t->next;
    t->next=NULL;
    delete n;
    
}
void dll::deletefirst()
{
    if(start)
    {
        node *n;
        n=start;
        start=n->next;
        n->next->prev=NULL;
        delete n;
    }
}
node* dll::search(int data)
{
    if(start)
    {
        node *t;
        t=start;
        while(t->next!=NULL)
            {
                if(t->item==data)
                    return t;   
                t=t->next;
            }
    }
            return NULL;
    
}
void dll::insertLast(int data)
{
    node *t;
    t=start;
    while(t->next)
        t=t->next;
    node *n=new node;
    n->next=NULL;
    n->item=data;
    n->prev=t;
    t->next=n;
    
}
void dll::displaylist()
{
    node *t;
    t=start;
    int i;
    for(i=1;t;i++)
    {
        cout<<"Item "<<i<<" = "<<t->item<<endl;
        t=t->next;
    }
    cout<<endl;
}
void dll::insertStart(int data)
{
    node *n=new node;
    if(start)
    {
        start->prev=n;
        n->next=start;
        n->prev=NULL;
        n->item=data;
        start=n;
    }
    else
    {
        start=n;
        n->prev=NULL;
        n->next=NULL;
        n->item=data;
    }
}
dll::dll()
{
    start=NULL;
}

int main()
{
    dll d1;
    d1.insertStart(1);
    d1.insertStart(2);
    d1.insertStart(3);
    d1.insertStart(4);
    d1.displaylist();
    d1.insertLast(5);
    d1.displaylist();
    node *n=d1.search(1);
    cout<<n->item<<endl;
    d1.deletefirst();
    d1.displaylist();
    d1.deletelast();
    d1.displaylist();
    d1.deleteAtNode(d1.search(2));
    d1.displaylist();
    d1.insertAtNode(d1.search(3),5);
    d1.displaylist();





    return 0;
}
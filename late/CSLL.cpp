#include<iostream>
using namespace std;
class node
{
    public:
    node *next;
    int item;
};
class csll
{
    private:
    node *last;
    public:
    csll();
    void insertStart(int data);
    void displaylist();
    void insertLast(int data);
    node* search(int data);
    void insertAfter(node*,int data);
    void deletefirst();
    void deletelast();
    void deleteAfterNode(node*);
    ~csll();
};
csll::~csll()
{
    while(last)
        deletefirst();
}
void csll::deleteAfterNode(node *n)
{
    node *t;
    if(n)
    {
        t=n->next;
        n->next=n->next->next;
        delete t;
    }

}
void csll::deletelast()
{
    node *n;
    n=last->next;
    while(n->next!=last)
            n=n->next;
    n->next=last->next;
    delete last;
    last=n;
}
void csll::deletefirst()
{
    node *n;
    if(last)
    {
        if(last->next==last)
        {
            node *n;
            n=last;
            n=NULL;
            delete n;
        }
        else
        {
            node *n;
            n=last->next;
            last->next=last->next->next;
            delete n;
        }
    }
    

}
void csll::insertAfter(node *temp,int data)
{   
    node *n=new node;
    n->item=data;
    if(temp)
    {
        n->next=temp->next;
        temp->next=n;
    }
    else
    {
        last=n;
        n->item=data;
        n->next=n;
    }
}
node* csll::search(int data)
{
    node *t;
    t=last;
    int i;
    for(i=1;t->next!=last;i++)
    {   
        if(t->item==data)
            return t;
        t=t->next;
    }
    if(t->next==last)
    {
        if(t->item==data)
            return t;
    }
    return NULL;
}
void csll::insertLast(int data)
{
    node *n=new node;
    if(last)
    {
        n->item=data;
        n->next=last->next;
        last->next=n;
        last=n;
    }
    else
    {
        last=n;
        n->item=data;
        n->next=last;
    }
}
void csll::displaylist()
{
    node *t;
    t=last;
    int i;
    for(i=1;t->next!=last;i++)
    {
        cout<<"Item "<<i<<" = "<<t->next->item<<endl;
        t=t->next;
    }
    if(t->next==last)
        cout<<"Item "<<i<<" = "<<t->next->item<<endl;
    cout<<endl;
}
void csll::insertStart(int data)
{
    node *n=new node;
    if(last)
    {
        n->next=last->next;
        n->item=data;
        last->next=n;
    }
    else
    {
            n->next=n;
            n->item=data;
            last=n;
    }
}
csll::csll()
{
    last=NULL;
}
int main()
{
    csll l1;
    l1.insertStart(20);
    l1.insertStart(21);
    l1.insertStart(22);
    l1.insertStart(23);
    l1.displaylist();
    l1.insertStart(55);
    l1.displaylist();
    l1.insertLast(25);
    l1.displaylist();
    node *n=l1.search(25);
    cout<<n->item<<endl;
    l1.insertAfter(l1.search(20),15);
    l1.displaylist();
    l1.deletefirst();
    l1.displaylist();
    l1.deletelast();
    l1.displaylist();
    l1.deleteAfterNode(l1.search(21));
    l1.displaylist();

    return 0;
}
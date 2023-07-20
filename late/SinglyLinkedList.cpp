#include<iostream>
using namespace std;
class node{
    public:node *next;
            int item;
};
class sll
{
    private:
        node *start;
    public:
        sll();
        void insertStart(int data);
        void insertLast(int data);
        node* searchnode(int data);
        void insertAtNode(node *n,int data);
        void displayList();
        void deletefirst();
        void deletelast();
        void deleteAtNode(node *n);
        ~sll();

};
sll::~sll()
{
    while(start)
        deletefirst();
}
void sll::deleteAtNode(node *n)
{
    node *t;
    t=start;
    int i;
    for(i=0;t->next!=n;i++)
        t=t->next;
    t->next=n->next;
    delete n;
}
void sll::deletelast()
{
    if(start)
    {
        node *n;
        n=start;
        int i;
        for(i=0;n->next->next;i++)
            n=n->next;
        delete n->next;
        n->next=NULL;
    }
}
void sll::deletefirst()
{
    if(start)
    {
        node *n;
        n=start;
        start=start->next;
        delete n;
    }
}
void sll::insertAtNode(node *n,int data)
{
    //this fuction will insert after the node you pass 
    node *t=new node;
    t->item=data;
    t->next=n->next;
    n->next=t;
}
node* sll::searchnode(int data)
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
    //its edge case is also statisfied when start==NULL or list is empty
}
void sll::displayList()
{
    node *t;
    t=start;
    int i;
    for(i=1;t;i++)
    {
        cout<<"Item No.= "<<i<<" "<<t->item<<endl;
        t=t->next;
    }
    cout<<endl;
}
void sll::insertLast(int data)
{
    node *n=new node;
    node *t;
    t=start;
    int i;
    n->item=data;
    n->next=NULL;
    if(t!=NULL)
    {
        for(i=0;t->next;i++)
            t=t->next;
        t->next=n;
    }
    else
    {
        start=n;
    }
    //remember rule of sir after traversing first make changes in new node then in other
    
}
void sll::insertStart(int data)
{
    node *n=new node;
    n->next=start;
    n->item=data;
    start=n;
}
sll::sll()
{
    start=NULL;
}
int main()
{
    sll l1;
    l1.insertStart(5);
    l1.insertStart(10);
    l1.insertStart(15);
    l1.displayList(); 
    l1.insertLast(20);
    l1.insertLast(25);
    l1.insertLast(30);
    l1.displayList();
    node *n;
    n=l1.searchnode(15);
    cout<<n->item<<endl;
    l1.insertAtNode((l1.searchnode(10)),11);
    l1.displayList();
    sll l2;
    l2.insertStart(5);
    l2.insertStart(11);
    l2.insertStart(10);
    l2.insertStart(15);
    l2.displayList();
    l2.deletefirst();
    l2.displayList();
    l2.deletelast();
    l2.displayList();
    l2.insertStart(2);
    l2.insertStart(3);
    l2.insertStart(4);
    l2.displayList();
    l2.deleteAtNode(l2.searchnode(2));
    l2.displayList();
    sll l3;
    l3.insertLast(55);
    l3.displayList();
    return 0;
}
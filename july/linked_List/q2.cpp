//define a method to count number of list item in singly linked list
#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    int item;
    node *next;
};
class SLL
{
    private:
        node *start;
    public:
        SLL();
        void insertAtStart(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfter(node *,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        void displayList();
        int countele();
        void reverseList();
        ~SLL();
};
void SLL::reverseList()
{
    if(start)
    {

        node *t1;
        node *t2;
        t2=start->next;
        int i;
        while(start->next)
        {
            t2=start->next;
            t1=t2->next;
            t2->next=start;
            start=t2;
        }
    }
}
int SLL::countele()
{
    if(start)
    {
        int i;
        node *t=start;
        for(i=0;t;i++)
        t=t->next;
        return i;
    }
    else
        return 0;
    
}
SLL::~SLL()
{
    while(start)
        deleteFirst();
}
void SLL::deleteNode(node *temp)
{
    node *t;
    if(start==NULL)
        cout<<"\nUnderflow";
    else 
    {
        if(temp)
        {
            if(start==temp)
            {
                start=temp->next;
                delete temp;
            }
            else
            {
                t=start;
                while(t->next!=temp)
                    t=t->next;
                t->next=temp->next;
                delete temp;                
            }
        }
    }

}
void SLL::deleteLast()
{
    node *t;
    if(start==NULL)
    {
        cout<<"\nUnderflow";
    }
    else if(start->next==NULL)
    {
        delete start;
        start=NULL;
    }
    else
    {
        t=start;
        while(t->next->next!=NULL)
            t=t->next;
        delete t->next;
        t->next=NULL;
    }
}
void SLL::deleteFirst()
{
    node *t;
    if(start)
    {
        t=start;
        start=start->next;
        delete t;
    }
}
void SLL::insertAfter(node *ptr,int data)
{
    node *n=new node;
    n->item=data;
    n->next=ptr->next;
    ptr->next=n;
}
node* SLL::search(int data)
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
void SLL::insertAtLast(int data)
{
    node *t;
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
        start=n;
    else
    {
     
     while(t->next!=NULL)
        t=t->next;
     t->next=n;
    }
}
void SLL::displayList()
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
void SLL::insertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    n->next=start;
    start=n;
}
SLL::SLL()
{
    start=NULL;
}
int main()
{
    SLL l1;
    l1.insertAtLast(55);
    l1.insertAtLast(44);
    l1.displayList();
    // l1.reverseList();
    // l1.displayList();
}

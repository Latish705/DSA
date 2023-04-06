#include<iostream>
#include<stdio.h>
using namespace std;

class node
{
    public:
        int item;
        node *next;
};

class SLL
{
    private:
        node *start;
        //node obj;
    public:
    void insertAtStart(int element);
    void insertStart(int element);
    void insertAtLast(int element);
    SLL();
};
SLL::SLL()
{
    start=NULL;
}
void SLL::insertAtStart(int element)
{
    node *n=new node;
    n->item=element;
    n->next=start;
    start=n;
}
void SLL::insertAtLast(int element)
{
    node *t;
    node *n=new node;
    n->item=element;
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



int main()
{
    return 0;
}
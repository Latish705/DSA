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
        int numOfNodes;
        
    public:
    int searchAtNode(int nodenum);
    void insertAtStart(int element);
    void insertStart(int element);
    void insertAtLast(int element);
    void deleteatnode();
    void deleteatLastNode();
    void insertAtNode(int,int );
    void displaylist();
    void deleteFirstNode();
    void reverseList();
    node* middleNode();
    SLL();
};
node* SLL::middleNode()
{
    node *t1;
    node *t2;
    t1=start;
    t2=start;
    while(t2->next)
    {
        t1=t1->next;
        t2=t2->next->next;
    }
    return t1;
}
void SLL::deleteatLastNode()
{
    node *t;
    int i;
    t=start;
    for(i=0;i<numOfNodes;i++)
    {
        if(t->next->next==NULL)
        {
            delete t->next;
            t->next=NULL;
        }
    }
}
void SLL::deleteFirstNode()
{
    node *t;
    if(start==NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    else
    {
         t=start->next;
        delete start;
        start=t;
        numOfNodes--;
    }
   
    
}
void SLL::insertAtNode(int nodeEle,int ele)
{
    node *t;
    t=start;
    int i;
    node *n;
    for(i=1;i<numOfNodes;i++)
    {
        if(i==nodeEle)
        {
            n=new node;
            n->item=ele;
            n->next=t->next;
            t->next=n;
            break; 
        }
        else
        {
             t=t->next;
        }
    }
}
int SLL::searchAtNode(int nodenum)
{
    //this is fuction to search the node with node element mean you will give node element and the match item in node will be returned
    int i;
    node *t;
    t=start;
    for(i=0;i<numOfNodes;i++)
    {

        if(t->item==nodenum)
        {
            break;
        }
        else
        {
            t=t->next;
        }
    }
    if(i==numOfNodes)
       {
            cout<<"Element not found ";
            return 0;
       } 
    if(i<numOfNodes)
        return i;
        //cout<<"Element found at index= "<<i<<endl;
        return -1;
}
SLL::SLL()
{
    start=NULL;
    numOfNodes=0;
}
//new version of insert at start previous was just too basic not statisfying all the conditions this will
void SLL::insertAtStart(int element)
{
    node *n=new node;
    n->item=element;
    if(start==NULL)
    {
        n->next=NULL;
        start=n;
        numOfNodes++;
    }
    else
    {
        n->next=start;
        start=n;
        numOfNodes++;
    }
    
}
void SLL::insertAtLast(int element)
{
    node *t;
    node *n=new node;
    n->item=element;
    n->next=NULL;
    if(start==NULL)
       {
            start=n;
        numOfNodes++;
       } 
    else
    {
        while(t->next!=NULL)
        {
            t=t->next;
            numOfNodes++;
        }
            
        t->next=n;
        numOfNodes++;
    }


}
//on 16/4/23 this function is created while making this there was just need to understand condition of loop properly
void SLL::displaylist()
{
    node *t;
    t=start;
    node *n;
    for(int i=1;t;i++)
    {
        cout<<"Node "<<i<<" =";
        cout<<t->item<<endl;
        t=t->next;
    }
    cout<<endl;
}
void SLL::reverseList()
{
    if(start)
    {
        node *t1;
        node *t2;
        t2=start->next;
        start->next=NULL;
        int i;
        while(start->next)
        {
            t1=t2->next;
            t2->next=start;
            start=t1->next;
            t2=start->next;
        }
    }
}


int main()
{
    SLL l1;
    l1.insertAtStart(5);
    l1.insertAtStart(8);
    l1.insertAtStart(22);
    l1.insertAtStart(33);
    l1.insertAtStart(5111);
    l1.insertAtStart(5552);
    l1.displaylist();
    cout<<l1.searchAtNode(22)<<endl;
    l1.insertAtNode(4,31);
    l1.displaylist();
    l1.deleteFirstNode();
    l1.displaylist();
    // l1.reverseList();
    // cout<<"\nReverse List is\n";
    // l1.displaylist();
    node *n=l1.middleNode();
    cout<<n->item;

    return 0;
}
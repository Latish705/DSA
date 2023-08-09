#include<iostream>
using namespace std;
class node{
    public:
    int item;
    node *prev;
    node *next;
};
class Deque
{
    private:
    node *front;
    node *rear;
    public:
    Deque();
    void insertFront(int data);
    void insertRear(int data);
    void deleteFront();
    void deleteRear();
    int getFront();
    void displayDeque();
};
void Deque::displayDeque()
{
    if(front)
    {
        node *t=front;
        while(t)
        {
            cout<<t->item<<" ";
            t=t->next;
        }
    }
    else
    cout<<"Deque is Empty"<<endl;
    
}
int Deque::getFront()
{
    return front->item;
}
void Deque::deleteRear()
{
    if(front)
    {
        node *n=rear;
        rear->prev->next=NULL;
        rear=rear->prev;
        delete n;
    }
    else
        cout<<"Deque is Empty"<<endl;
}
void Deque::deleteFront()
{
    if(front)
    {
        node *n=front;
        front=front->next;
        delete n;
    }
    else
        cout<<"Empty Deque"<<endl;
}
void Deque::insertRear(int data)
{
    node *n=new node;
    if(front)
    {
        n->item=data;
        n->prev=rear;
        n->next=NULL;
        rear=n;
    }
    else
    {
        n->next=NULL;
        n->item=data;
        n->prev=NULL;
        front=n;
        rear=n;
    }
}
void Deque::insertFront(int data)
{
    node *n=new node;
    if(front)
    {
        n->item=data;
        n->prev=NULL;
        n->next=front;
        front->prev=n;
        front=n;
    }
    else
    {
        n->item=data;
        n->next=NULL;
        n->prev=NULL;
        front=n;
        rear=n;
    }
}
Deque::Deque()
{
    front=NULL;
    rear=NULL;
}
int main()
{
    Deque d1;
    d1.insertFront(55);
    d1.insertFront(33);
    d1.displayDeque();
    return 0;
}
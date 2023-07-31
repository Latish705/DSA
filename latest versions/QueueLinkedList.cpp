#include<iostream>
using namespace std;


class node
{
    public:
    int item;
    node *next;
};

class queue
{
    private:
    node *front;
    node *rear;
    public:
    queue();
    void insert(int data);
    int viewRear();
    int viewFront();
    void DeleteEleOfQueue();

};
void queue::DeleteEleOfQueue()
{
    if(front)
    {
        node *n=front;
        
    }

}
int queue::viewRear()
{
    return rear->item;
}
int queue::viewFront()
{
    return front->item;
}
void queue::insert(int data)
{
    node *n=new node;
    if(front)
    {
        n->item=data;
        n->next=NULL;
    }
    else
    {
        n->next=NULL;
        n->item=data;
        rear->next=n;
    }
}
queue::queue()
{
    front=NULL;
    rear=NULL;
}


int main()
{
    return 0;
}
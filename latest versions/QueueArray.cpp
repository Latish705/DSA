#include<iostream>
using namespace std;


class queue
{
    private:
    int capacity;
    int front;
    int rear;
    int *ptr;
    public:
    queue(int data);
    void insert(int data);
    bool isFull();
    void viewRear();
    void viewFront();
    void deleteEle();
    ~queue();
    bool isQueueOverFlow();
    bool isQueueUnderFlow();
    int countNumber();
};
int queue::countNumber()
{
    int i=front;
    while(i!=rear)
    {
        if(i==capacity-1)
            i=0;
    }
    return i;
}
bool queue::isQueueUnderFlow()
{
    return rear==-1;
}
bool queue::isQueueOverFlow()
{
    if((front==0&&rear==(capacity-1))||rear+1==front)
        return 1;
    return 0;
}
queue::~queue()
{
    delete[] ptr;
}
void queue::deleteEle()
{
    if(front==-1)
        cout<<"Queue is Empty"<<endl;
    else if((front==rear)!=-1)
    {
        front=-1;
        rear=-1;
    }
    else if(front==capacity-1)
        front=0;
    else
        front++;
}
void queue::viewFront()
{
    if(rear==-1)
        cout<<"Queue is Empty"<<endl;
    else
        cout<<"Front element is "<<ptr[front]<<endl;
}
void queue::viewRear()
{
    if(rear==-1)
        cout<<"Queue is Empty"<<endl;
    else
        cout<<"Rear element is "<<ptr[rear]<<endl;
}
bool queue::isFull()
{
    if((front==0&&rear==(capacity-1))||rear+1==front)
        return 1;
    return 0;
}
void queue::insert(int data)
{
    if(!isFull())
        cout<<"Queue is Full"<<endl;
    else if(front>0&&rear==capacity-1)
    {
        rear=0;
        ptr[rear]=data;
    }
    else if(front==-1&&rear==-1)
    {
        rear=0;
        front=0;
        ptr[rear]=data;
    }
    else
    {
        rear++;
        ptr[rear]=data;
    }
}

queue::queue(int data)
{
    ptr=new int[data];
    capacity=data;
    front=-1;
    rear=-1;
}


int main()
{
    return 0;
}
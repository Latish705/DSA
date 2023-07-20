#include<iostream>
using namespace std;

class queue
{
    private:
    int capacity;
    int front,rear;
    int *ptr;
    public:
    void insert(int data);
    queue(int data);
    void display();
    bool isFull();
    bool isEmpty();
    int viewRear();
    int viewFront();
    void deleteFront();
};
void queue::deleteFront()
{
    if(isEmpty())
        cout<<"Queue is Empty"<<endl;
    else if(front==rear)
    {
        rear=-1;
        front=-1;
    }
    else if(front==capacity-1)
        front=0;
    else
        front++;
}
int queue::viewFront()
{
    if(front!=-1)
        return ptr[front];
    return -1;
}
int queue::viewRear()
{
    if(rear!=-1)
    return ptr[rear];
    return -1;
}
bool queue::isEmpty()
{
    return rear==-1;
}
bool queue::isFull()
{
    return front==0&&rear==capacity-1||rear+1==front;

}
void queue::display()
{
     int i;  
    if(rear == -1)  
    {  
        cout<<"Empty queue"<<endl;  
    }  
    else  
    {   cout<<"\nprinting values .....\n";  
        for(i=front;i<=rear;i++)  
        {  
            cout<<ptr[i]<<endl;  
        }     
    }  
}
void queue::insert(int data)
{
    if(isFull())
    {
        cout<<"Queue is Full"<<endl;
    }
    else if(isEmpty())
    {
        rear=0;
        front=0;
        ptr[rear]=data;
    }
    else if(rear==capacity-1)
    {
        rear=0;
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
    front=-1;
    rear=-1;
    capacity=data;
}
int main()
{
    queue q(5);
    q.insert(5);
    q.insert(1);
    q.insert(2);
    q.insert(3);
    q.insert(4);
    q.display();
    return 0;
}
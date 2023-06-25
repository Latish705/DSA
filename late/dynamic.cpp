#include<iostream>
#include<math.h>
using namespace std;

class DynamicArray{
    private:
        int capacity;
        int lastindex;
        int *ptr;
    public:
        DynamicArray(int size);
        void doubleArray();
        void halfArray();
        int getcapacity();
        int isEmpty();
        void append(int data);
        //own fuction
        void displayArray();
        void insert(int index,int data);
        void edit(int index,int data);
        void deleteEle(int index);
        int isFull();
        int getEle(int index);
        int countEle();
        int findEle(int data);
        ~DynamicArray();
};
int DynamicArray::findEle(int data)
{
    int i;
    for(i=0;i<lastindex;i++)
    {
        if(ptr[i]==data)
            return i; 
    }
    return -1;
}
DynamicArray::~DynamicArray()
{
    delete []ptr;
}
int DynamicArray::countEle()
{
    return lastindex+1;
}
int DynamicArray::getEle(int index)
{
    if(index>=0 && index<=lastindex)
        return ptr[index];
    cout<<"Invalid Index"<<endl;
    return -1;
}
int DynamicArray::isFull()
{
    return lastindex==capacity-1;
}
void DynamicArray::deleteEle(int index)
{
    int i,cc;
    if(capacity%2)
        cc=ceil((float)capacity/2);
    else
        cc=capacity/2;
    int *n;
    for(i=index;i<lastindex;i++)
        ptr[i]=ptr[i+1];
    lastindex--;
    if(lastindex==((capacity-1)/2))
        n=new int[cc];
}
void DynamicArray::edit(int index,int data)
{
    if(index>=0&&index<=lastindex)
        ptr[index]=data;
}
void DynamicArray::insert(int index,int data)
{
    if(index<0 || index>capacity)
    {
        cout<<"Invalid Index"<<endl;
    }    
    else
    {
        if(lastindex==capacity-1)
            doubleArray();
        int i;
        for(i=lastindex;i>index;i--)
            ptr[i]=ptr[i-1];
        ptr[index]=data;

    }
}
void DynamicArray::displayArray()
{
    int i;
    for(i=0;i<=lastindex;i++)
    {
        cout<<*(ptr+i)<<"  ";
    }
    cout<<endl;
}
void DynamicArray::append(int data)
{
    if(lastindex==capacity-1)
    {
        doubleArray();
    }
        lastindex++;
        ptr[lastindex]=data;
}
int DynamicArray::isEmpty()
{
    if(lastindex==-1)
        return 1;
    else 
        return 0;
}
int DynamicArray::getcapacity()
{
    return capacity;
}
void DynamicArray::halfArray()
{
    int *n;
    n=new int[capacity/2];
    int i;
    for(i=0;i<=lastindex;i++)
    {
        n[i]=ptr[i];
    }
    delete ptr;
    ptr=n;
}
DynamicArray::DynamicArray(int size)
{
    ptr=new int[size];
    lastindex=-1;
    capacity=size;
}
void DynamicArray::doubleArray()
{
    int *n;
    int i;
    n=new int[capacity*2];
    for(i=0;i<lastindex;i++)
    {
        n[i]=ptr[i];
    }
    delete ptr;
    ptr=n;
    capacity=capacity*2;
}
int main()
{
    DynamicArray a(5);

    a.append(5);
    a.append(6);
    a.append(6);
    a.append(6);
    a.append(6);
    a.displayArray();
    a.append(7);
    a.displayArray();
    cout<<endl;
    cout<<a.getcapacity()<<endl;
    
    return 0;
}
#include<iostream>
using namespace std;


class DynArray{
    private:
    int capacity;
    int lastindex;
    int *ptr;
    public:
    void operator[](int size);
    DynArray(int size);
    void doubleArray();
    void halfArray();
    int getCapacity();
    bool isEmpty();
    void append(int data);
    void insert(int index,int data);
    void edit(int index,int data);
    void deleteEle(int index);
    bool isFull();
    int getAtIndex(int index);
    int getCount();
    int findEle(int data);
    ~DynArray();
};
int DynArray::findEle(int data)
{
   if(lastindex==-1)
    {
        cout<<"Array is empty"<<endl;
        return -1;
    }
    else
    {
        int i;
        for(i=0;i<=lastindex;i++)
        {
            if(ptr[i]==data)
                return i;
        }
        return -1;
    }
}
DynArray::~DynArray()
{
    delete []ptr;
}
int DynArray::getCount()
{
    return lastindex+1;
}
int DynArray::getAtIndex(int index)
{
    if(index<0||index>lastindex+1)
    {
        cout<<"Invalid Index"<<endl;
        return -1;
    }
    return ptr[index];
}
bool DynArray::isFull()
{
    return capacity==lastindex+1;
}
void DynArray::deleteEle(int index)
{
    if(index<0||index>lastindex+1)
        cout<<"Invalid Index"<<endl;
    else{
        int i;
        for(i=index;i<lastindex;i++)
            ptr[i]=ptr[i+1];
    }
}
void DynArray::edit(int index,int data)
{
    if(index<0||index>lastindex+1)
        cout<<"Invalid Index"<<endl;
    else
        ptr[index]=data;
}
void DynArray::insert(int index,int data)
{
    if(index<0||index>lastindex+1)
        cout<<"Invalid Index"<<endl;
    else if(lastindex+1==capacity)
    {
        doubleArray();
        int i;
        lastindex++;
        for(i=lastindex;i!=index;i++)
            ptr[i]=ptr[i-1];
        ptr[index]=data;
    }
    else
    {
        lastindex++;
        ptr[lastindex]=data;
    }

}
void DynArray::append(int data)
{
    if(lastindex==capacity-1)
    {
        doubleArray();
        lastindex++;
        ptr[lastindex]=data;
    }
    else
    {
        lastindex++;
        ptr[lastindex]=data;
    }
    
}
bool DynArray::isEmpty()
{
    return lastindex==-1;
}
int DynArray::getCapacity()
{
    return capacity;
}
void DynArray::halfArray()
{
    if(capacity%2)
    {
        capacity=capacity/2+1;
        int *pt=new int[capacity];
        delete []ptr;
        ptr=pt; 
    }
    else
    {
        capacity=capacity/2+1;
        int *pt=new int[capacity];
        delete []ptr;
        ptr=pt;
    }
}
void DynArray::doubleArray()
{
    capacity=capacity*2;
    int *pt=new int[capacity*2];
    delete []ptr;
    ptr=pt;
}
DynArray::DynArray(int size)
{
    ptr=new int[size];
}

void DynArray::operator[](int size)
    {
        ptr=new int[size];
    }

int main()
{
    
    return 0;
}
#include<iostream>
using namespace std;

class Array
{
    private:
    int capacity;
    int lastindex;
    int *ptr;
    public:
    //don't forget to make copy constructor
    Array(int data);
    bool isEmpty();
    void append(int data);
    void displayArray();
    void insert(int index,int data);
    void edit(int index,int data);
    void deleteEle(int index);
    bool isFull();
    int getele(int index);
    int count();
    int getCapacity();
    ~Array();
    int findEle(int data);
    //void sort();
    int findGreatest();
    int findSmallest();
    void operator=(Array &arr);

};
void Array::operator=(Array &arr)
{
    arr.capacity=capacity;
    arr.lastindex=lastindex;
    ptr=new int[getCapacity()];
    int i=0;
    while(i-1!=lastindex)
        arr.ptr[i]=ptr[i];
}
int Array::getCapacity()
{
    return capacity;
}
int Array::findSmallest()
{
    int min=ptr[0];
    int i;
    for(i=0;i<=lastindex;i++)
    {
        if(ptr[i]<min)
            min=ptr[i];
    }
    return i;
}
int Array::findGreatest()
{
    int max=-1;
    int i;
    for(i=0;i<=lastindex;i++)
    {
        if(ptr[i]>max)
            max=ptr[i];
    }
    return i;
}
int Array::findEle(int data)
{
    if(lastindex!=-1)
    {
        int i;
        for(i=0;i<=lastindex;i++)
        {
            if(ptr[i]==data)
                return i;
        }
        cout<<"Element not found"<<endl;
        return -1;
    }
    return -1;
}
Array::~Array()
{
    delete []ptr;
}
int Array::count()
{
    return lastindex+1;
}
int Array::getele(int index)
{
    if(index<0||index>lastindex+1)
    {
        cout<<"Invalid Index"<<endl;
        return -1;
    }
    else
    {
        return ptr[index];
    }
}
bool Array::isFull()
{
    return lastindex+1==capacity;
}
void Array::deleteEle(int index)
{
    if(index<0||index>lastindex+1)
        cout<<"Invalid Index"<<endl;
    else
        {
            int i;
            for(i=index;i!=lastindex;i++)
                ptr[i]=ptr[i+1];
            lastindex--;
        }
}
void Array::edit(int index,int data)
{
    if(index<0 || index>lastindex+1)
        cout<<"Invalid Index"<<endl;
    else
        ptr[index]=data;
}
void Array::insert(int index,int data)
{
    if(capacity==lastindex+1)
        cout<<"Array is overflow"<<endl;
    else if(index<0||index>lastindex+1)
        cout<<"Invalid Index"<<endl;
    else
    {
        lastindex++;
        int i;
        for(i=lastindex;i!=index;i--)
            ptr[i]=ptr[i-1];
        ptr[index]=data;
    }

}
void Array::displayArray()
{
    if(lastindex!=-1)
    {
        int i;
        for(i=0;i<=lastindex;i++)
            cout<<"Element No. "<<i+1<<" is "<<ptr[i]<<endl;
        cout<<endl;
    }
}
void Array::append(int data)
{
    if(lastindex==capacity-1)
        cout<<"Array is overflow"<<endl;
    else
        lastindex++;
        ptr[lastindex]=data;
}
bool Array::isEmpty()
{
    return lastindex==-1;
}
Array::Array(int data)
{
    ptr=new int[data];
    lastindex=-1;
    capacity=data;
}

//int main()
//{
    // Array a(7);
    // a.append(14);
    // a.displayArray();
    // a.append(15);
    // a.append(16);
    // a.append(18);
    // a.append(19);
    // a.append(20);
    // a.displayArray();
    // a.insert(3,17);
    // a.displayArray();
  //  return 0;
//}
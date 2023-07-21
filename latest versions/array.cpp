#include<iostream>
using namespace std;


class Array
{
    private:
        int capacity;
        int lastindex;
        int *ptr;
    public:
            Array(int );
            int Arrayempty();
            void append(int data);
            void displayarray();
            void insert(int , int );

};
void Array::insert(int index,int data)
{
    if(lastindex==capacity-1)
    {
        cout<<"Array is already full"<<endl;
    }
    else if(index<0 || index>lastindex+1)
    {
        cout<<"Invalid Index"<<endl;
    }
    else
    {
        int temp,i;
        for(i=lastindex;i>=index;i++)
        {
            ptr[i+1]=ptr[i];
        }
        ptr[index]=data;
        lastindex++;

    }
}
Array::Array(int size)
{
    ptr=new int[size];
    lastindex=-1;
}
int Array::Arrayempty()
{
    if(lastindex==-1)
        return 1;
    else
        return 0;
}
void Array::append(int data)
{
    if(lastindex==capacity-1)
        cout<<"Array is already full"<<endl;
    else
        {
            lastindex++;
            ptr[lastindex]=data;
        }
}
void Array::displayarray()
{
    int i;
    for(i=0;i<=lastindex;i++)
    {
        cout<<"Element "<<i+1<<" is : "<<ptr[i]<<endl;
    }
}
int main()
{
    Array a(5);
    a.append(5);
    a.displayarray();
    return 0;
}
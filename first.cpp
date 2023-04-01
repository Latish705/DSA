#include<iostream>
using namespace std;


class Array
{
    private:
    int capacity;
    int lastindex;
    int *ptr=NULL;
    public:
    void append()
    {
        //append will be a fuction in this class which will help to input number the last index
    }
    Array(int size)
    {
         //inside Array constructor we will make dynamic array with the help of new
        int *ptr=NULL;
        ptr=new int[size];
        capacity=size;
        lastindex=-1;
        cout<<capacity<<endl;
        cout<<lastindex<<endl;

    }
    string checkArrayEmpty()
    {
        if(lastindex==-1)
        return "True";
        else
        return "False";
    }
    void append(int num);
    
    void insert(int index,int num)
    {
        ptr=new int[(lastindex+capacity)+1];
        *(ptr+index)=num;
    }
    void edit()
    {

    }
    void displayArray()
    {
        int i;
        for(i=0;i<=lastindex;i++)
        {
            cout<<*(ptr+i);
        }
    }
};

void Array::append(int num)
{
        if(lastindex==capacity-1)
        {
        cout<<endl;
        cout<<"Error Array is already full";
        }
        else
        {
            lastindex++;
            ptr[lastindex]=num;
            

        }

       

    }

int main()
{
    Array a(5);
    cout<<a.checkArrayEmpty();
    a.append(5);
    a.displayArray();
    return 0;
}
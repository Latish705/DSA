#include <iostream>
using namespace std;

class Array
{
private:
    int capacity;
    int lastindex;
    int *ptr;

public:
    Array(int size);
    string checkArrayEmpty();
    void append(int num);
    void insert(int element, int index);
    void edit(int element,int index);
    void displayArray();
};
void Array::displayArray()
    {
        int i;
        for (i = 0; i <= lastindex; i++)
        {
            cout << *(ptr + i);
        }
        cout<<endl;
    }
void Array::edit(int index,int num)
{

}
void Array::insert(int index, int num)
    {
        if(lastindex==capacity-1)
        {
            cout<<"Array is already full"<<endl;
        }
        else if(index<0 || index>=lastindex+1)
        {
            cout<<"Invalid Index"<<endl;
        }
        else
        {
            int i;
            for(i=lastindex;i>=index;i--)
            {
                ptr[i+1]=ptr[i];
            }
            ptr[index]=num;
            lastindex++;
        }
    }
Array::Array(int size)
{
        // inside Array constructor we will make dynamic array with the help of new
        ptr = new int[size];
        capacity = size;
        lastindex = -1;
        cout << capacity << endl;
        cout << lastindex << endl;
    }

string Array::checkArrayEmpty()
{
    if (lastindex == -1)
        return "True";
    else
        return "False";
}

void Array::append(int num)
{
    if (lastindex == capacity - 1)
    {
        cout << endl;
        cout << "Error Array is already full";
    }
    else
    {
        lastindex++;
        ptr[lastindex] = num;
    }
}

int main()
{
    Array a(5);
    cout << a.checkArrayEmpty();
    a.append(5);
    cout << endl;
    a.append(6);
    a.displayArray();
    a.insert(1,9);
    a.displayArray();
    return 0;
}
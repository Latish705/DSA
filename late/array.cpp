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
    int isEmpty();
    void append(int data);
    void displayArray();
    void insert(int index, int data);
    void edit(int index, int data);
    void deleteElement(int index);
    int isArrayfull();
    void numberEle();
    int findEle(int element);
    ~Array();
};
int findEle(int element)
{
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] == element)
            return i;
        cout >> "Not found" << endl;
        return -1;
    }
}
Array::~Array()
{
    delete[] ptr;
}
void Array::numberEle()
{
    return lastindex + 1;
}
int Array::isArrayfull()
{
    if (lastindex == capcity - 1)
        return 1;
    return 0;
}
void Array::deleteElement(int index)
{
    int i;
    for (i = index; i < lastindex; i++)
        ptr[i] = ptr[i + 1];
    lastindex--;
}
void Array::edit(int index, int data)
{
    if (index < 0 || index > lastindex)
        cout << "Invalid Index" << endl;
    else
        ptr[index] = data;
}
void Array::insert(int index, int data)
{
    if (lastindex == capacity - 1)
        cout << "Array is already full" << endl;
    else if (index < 0 || index > lastindex + 1)
        cout << "Invalid Index" << endl;
    else
    {
        int i;
        for (i = lastindex; i >= index; i--)
            ptr[i + 1] = ptr[i];
        ptr[index] = data;
        lastindex++;
    }
}
void Array::displayArray()
{
    int i;
    for (i = 0; i <= lastindex; i++)
        cout << ptr[i] << " ";
    cout << endl;
}
Array::Array(int size)
{
    ptr = new int[size];
    lastindex = -1;
    capacity = size;
}
int Array::isEmpty()
{
    if (lastindex == -1)
        return 1;
    return 0;
}
void Array::append(int data)
{
    if (lastindex == capacity - 1)
        cout << "Array is already full" << endl;
    else
    {
        lastindex++;
        ptr[lastindex] = data;
    }
}

int main()
{
    Array a(7);
    a.append(4);
    a.append(9);
    a.append(6);
    a.append(2);
    a.displayArray();
    a.insert(2, 11);
    a.displayArray();
    a.insert(3, 22);
    a.displayArray();
    a.deleteElement(3);
    a.displayArray();
    return 0;
}
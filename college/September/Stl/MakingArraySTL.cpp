#include <iostream>
using namespace std;
template <typename X>
class Array
{
    private:
        int capacity;
        int lastindex;
        X *ptr;

    public:
        Array<X>(int size);
        int isEmpty();
        void append(X data);
        void displayArray();
        void insert(int index, X data);
        void edit(int index, X data);
        void deleteElement(int index);
        int isArrayfull();
        void numberEle();
        int findEle(X element);
        ~Array<X>();
};
template<typename X>int Array<X>::findEle(X element)
{
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] == element)
            return i;
        cout << "Not found" << endl;
        return -1;
    }
}
template<typename X>Array<X>::~Array<X>()
{
    delete[] ptr;
}
template<typename X>void Array<X>::numberEle()
{
    return lastindex + 1;
}
template<typename X>int Array<X>::isArrayfull()
{
    if (lastindex == capacity - 1)
        return 1;
    return 0;
}
template<typename X>void Array<X>::deleteElement(int index)
{
    int i;
    for (i = index; i < lastindex; i++)
        ptr[i] = ptr[i + 1];
    lastindex--;
}
template<typename X>void Array<X>::edit(int index, X data)
{
    if (index < 0 || index > lastindex)
        cout << "Invalid Index" << endl;
    else
        ptr[index] = data;
}
template<typename X>void Array<X>::insert(int index, X data)
{
    if (lastindex == capacity - 1)
        cout << "Array<X> is already full" << endl;
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
template<typename X>void Array<X>::displayArray()
{
    int i;
    for (i = 0; i <= lastindex; i++)
        cout << ptr[i] << " ";
    cout << endl;
}
template<typename X> Array<X>::Array(int size)
{
    ptr = new X[size];
    lastindex = -1;
    capacity = size;
}
template<typename X> int Array<X>::isEmpty()
{
    if (lastindex == -1)
        return 1;
    return 0;
}
template<typename X>void Array<X>::append(X data)
{
    if (lastindex == capacity - 1)
        cout << "Array<X> is already full" << endl;
    else
    {
        lastindex++;
        ptr[lastindex] = data;
    }
}

int main()
{
    Array<int> a(7);
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
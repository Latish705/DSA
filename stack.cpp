#include<iostream>
#include<Arrayclass.cpp>
using namespace std;
class stack:private Array
{
    private:

    public:
    stack(int size);


};
stack::stack(int size)
{
    Array(size);
}

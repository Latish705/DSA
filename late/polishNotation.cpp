#include<iostream>
using namespace std;

class polishnotation
{
    public:
    int PreAdd(operator+,int a,int b);

};
int polishnotation::PreAdd(operator+,int a,int b)
{
    return a+b;
}

int main()
{
    polishnotation c;
    int d=c.PreAdd(+,5,6);
    cout<<d<<endl;
    return 0;
}
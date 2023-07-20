#include<iostream>
#include<array>
using namespace std;


int main()
{
    array<int,5>a={1,2,3,4,5};
    array<int,5>::const_reverse_iterator it;
    it=a.crbegin();
    while(it!=a.crend())
    {
        cout<<*it<<" ";
        it++;
    }
    return 0;
}
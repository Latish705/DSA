#include<iostream>
using namespace std;


int main()
{
    array<int,10>a;
    array<int,10>::iterator it;
    it=a.begin();
    for(;it!=a.end();it++)
        cin>>*it;
    return 0;
}
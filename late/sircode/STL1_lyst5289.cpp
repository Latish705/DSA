#include<iostream>
#include<array>
using namespace std;

int main()
{
    array <int,5> a1={50,70,20,30,40};
    array <int,5> a2={3,6,9,1,4};
    a1.swap(a2);

    cout<<a1.size()<<endl;
    int *p=a1.data();
    cout<<*p<<endl;
    cout<<a1.empty()<<endl;
    cout<<a1.front()<<" "<<a1.back()<<endl;


    //Explicit Iterator
    array<int,5>::reverse_iterator it;
    for(it=a1.rbegin();it!=a1.rend();it++)
    {
        cout<<*it<<" ";
    }
    it=a1.rbegin();
    *(it+2)=100;
    cout<<endl;
    //Implicit Iterator
    for(auto x : a1)
        cout<<" "<<x;
    cout<<endl;

}
#include<iostream>
using namespace std;


int main()
{
    array<float,5>a={1.1,2.2,3.3,4.4,5.5};
    float avg=0;
    array<float,5>::const_iterator it;
    it=a.cbegin();
    for(;it!=a.cend();it++)
    {
        avg=avg+*it;
    }
    cout<<"Average of five number is "<<avg<<endl;
    return 0;
}
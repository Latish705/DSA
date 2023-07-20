#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int,4>a;
    array<int,4>c;
    a.swap(c);
    for(auto x : c)
        cout<<" "<<x;

    return 0;
}
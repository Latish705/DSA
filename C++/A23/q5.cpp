#include<iostream>
using namespace std;


int main()
{
    int l,b,h;
    cout<<"Enter lenght breadth height of cuboid to calculate its volume"<<endl;
    cin>>l>>b>>h;
    float vol=l*b*h;
    cout<<"Volume of cuboid is "<<vol<<endl;
    return 0;
}
#include"array.cpp"
#include<iostream>
using namespace std;

class extendArray:public Array{
    void sort();
};
void extendArray::sort()
{
    int i,j;
    int temp;
    for(i=0;i<count()-1;i++)
    {
        for(j=0;j<count()-1;j++)
        {
            if(ptr[j]>ptr[j+1])
            {
                temp=ptr[j];
                ptr[j]=ptr[j+1];
                ptr[j+1]=temp;
            }
        }
    }
}
int main()
{

    return 0;
}
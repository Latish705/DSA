#include<iostream>
using namespace std;
class node
{
    public:
    int item;
    node *next;
};

class SLL
{
    private:
    node *start;
    node i;
    public:
    SLL();
    void insert(int element);
};

void SLL::insert(int element)
{
    start=new node[1];
    start->item=element;
    start->next=new node[1];
}




SLL::SLL()
{
    start=NULL;

}


int main()
{
    SLL a();
    a.insert(5);
    

    return 0;
}
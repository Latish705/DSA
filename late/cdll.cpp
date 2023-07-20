#include<iostream>
using namespace std;
class node
{
    public:
    node *next;
    node *prev;
    int item;
};

class cdll
{
    private:
    node *start;
    public:
    cdll();
    void insertStart(int data);
    void displaylist();
    void insertLast(int data);
    void search(int data);

};
void cdll::search(int data)
{
    node *n;
    n=start;
    int i;
    for(i=1;n->next!=start;i++)
    {
        if(n->item==data)
            return n;
    }
    if(n->next->item==data)
        return n->next;
    return NULL;
}
void cdll::insertLast(int data)
{
    node *n=new node;
    n->item=data;
    if(start)
    {
        n->next=start;
        n->prev=start->prev;
        n->prev->next=n;
        n->next->prev=n;
    }
    else
    {
        n->next=n;
        n->prev=n;
        start=n;   
    }
}
void cdll::displaylist()
{
    node *n;
    n=start;
    int i;
    for(i=1;n->next!=start;i++)
    {
        cout<<"Item "<<i<<" = "<<n->item<<endl;
        n=n->next;
    }
    if(n->next==start)
        cout<<"Item "<<i<<" = "<<start->prev->item<<endl;
    cout<<endl;
}
void cdll::insertStart(int data)
{
    node *n=new node;
    n->item=data;
    if(start)
    {
        n->next=start;
        n->prev=start->prev;
        start->prev->next=n;
        start->prev=n;
        start=n;
    }
    else
    {
        n->next=n;
        n->prev=n;
        start=n;
    }

}
cdll::cdll()
{
    start=NULL;
}
int main()
{
    cdll l1;
    l1.insertStart(5);
    l1.displaylist();
    l1.insertStart(15);
    l1.insertStart(16);
    l1.insertStart(17);
    l1.insertStart(18);
    l1.displaylist();
    l1.insertLast(25);
    l1.displaylist();
    return 0;
}
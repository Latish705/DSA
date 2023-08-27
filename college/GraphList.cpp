#include<iostream>
using namespace std;
class node
{
    public:
    int vertex;
    node *next;
    node()
    {
        next=NULL;
    }
};  
class AdjList
{
    private:
    node *start;
    public:
    AdjList()
    {
        next=NULL;
    }
    void insertAtBeginnning(int data)
    {
        node *n=new node;
        n->vertex=data;
       if(start)
       {
            n->next=start;
            start=n;    
       }
       else
       {
            start=n;
       }
    }
    void DisplayList()
    {
        node *t;
        t=start;
        while(t)
        {
            cout<<
        }
    }
};
class Graph
{
    private:
        int v_count;
        AdjList *arr;
    public:
        Graph();
        void CreateGraph(int,int);
};
void Graph::CreateGraph(int v_node,int e_count)
{
    int u,v;
    adj=new AdjList[v_node];
    for(j=1;j<=edges;j++)
        {
            cout<<"Enter the connecting node  : ";
            cin>>u>>v;
            arr[u].insertAtBeginnning(v);
            arr[v].insertAtBeginnning(u);
        }
}
Graph::Graph()
{
    arr=NULL;
}


int main()
{

    return 0;
}
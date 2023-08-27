#include<iostream>
using namespace std;

class Graph
{
    private:
    int v_count;
    int e_count;
    int **adj;
    public:
    void createGraph(int nodes,int edges);
    void DisplayGraph();
    void printAdjacentNode(int);
    bool CheckIsolated(int);
    ~Graph();
};
Graph::~Graph()
{
    int i;
    for(i=0;i<v_count;i++)
        delete []adj[i];
    delete []adj;
}
bool Graph::CheckIsolated(int node_no)
{
    if(node_no<v_count && node_no>=0)
    {
        int i;
        for(i=0;i<v_count;i++)
        {
            if(adj[node_no][i]==0)
            {
                flag=0;
                break;
            }                
        }
        if(flag==0)
            return flag;
        return flag;
    }
}
void Graph::printAdjacentNode(int node_no)
{
    if(node_no<v_count && node_no>=0)
    {
        int i;
        for(i=0;i<v_count;i<<)
        {
            if(adj[node_no][i]!=0)
                cout<<"("<<node_no<<","<<i<<")";
        }
        cout<<endl;
    }
}
void Graph::DisplayGraph()
{
    int i,j;
    for(i=0;i<v_count;i++)
    {
        for(j=0;j<v_count;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Graph::createGraph(int nodes,int edges)
{
        v_count=nodes;
        e_count=edges;
        int u,v;
        adj=new int*[nodes];
        int i=0,j;
        while(i<nodes)
        {
            adj[i]=new int[nodes];
            i++;
        }
        for(i=0;i<nodes;i++)
        {
            for(j=0;j<nodes;j++)
                adj[i][j]=0;
        }
        //inputing information
        for(j=1;j<=edges;j++)
        {
            cout<<"Enter the connecting node  : ";
            cin>>u>>v;
            adj[u][v]=1;
            adj[v][u]=1;
        }
         
}
int main()
{
    Graph g;
    g.createGraph(5,6);
    g.DisplayGraph();
    g.printAdjacentNode()
    return 0;
}
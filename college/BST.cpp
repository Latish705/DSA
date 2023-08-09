#include<iostream>
using namespace std;

class node
{
    public:
    node *right;
    node *left;
    int item;
};

class BST
{
    private:
    node *root;
    public:
    BST();
    bool isTreeEmpty();
    void insert(int data);
    void preorderTraversing();
};
void BST::preorderTraversing()
{
    
}
void BST::insert(int data)
{
    if(root)
    {
        node *n=new node;
        n->item=data;
        node *t=root;
        while(t->left||t->right)
        {
            if(t->item>data)
                t=t->right;
            else
                t=t->left;
        }
        if(t->item>data)
            t->right=n;
        else
            t->left=n;
    }
}
bool BST::isTreeEmpty()
{
    return root==NULL;
}
BST::BST()
{
    root=NULL;
}
int main()
{

    return 0;
}
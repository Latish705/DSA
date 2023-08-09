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
    void preorderTraversing(node *root);
    node *GetRoot();
};
node *BST::GetRoot()
{
    return root;
}
void BST::preorderTraversing(node *root)
{
    if(root)
    {
        preorderTraversing(root->left);
        preorderTraversing(root->right);
        cout<<root->item<<" ";
    }
}
void BST::insert(int data)
{
    node *n=new node;
    n->item=data;
    if(root)
    {
        node *t=root;
        while(t->left||t->right)
        {
            if(t->item>data)
                t=t->right;
            else if(t->item<data)
                t=t->left;
            else
                break;
        }
        if(t->item>data)
            t->right=n;
        else
            t->left=n;
    }
    else
    {
        root=n;
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
    BST b1;
    b1.insert(12);
    b1.preorderTraversing(b1.GetRoot());
    b1.insert(11);
    b1.insert(15);
    // b1.insert(16);
    // b1.insert(17);
    // b1.insert(13);
    // b1.insert(44);
    // b1.insert(1);
    b1.preorderTraversing(b1.GetRoot());
    return 0;
}
#include<iostream>
using namespace std;

class node
{
    public:
    int item;
    node *left;
    node *right;
};
class BST
{
    private:
    node *root;
    public:
    BST();
    bool isEmpty();
    void insert(int data);
    void preorderTraversing(node *root);
    void inorderTraversing(node *root);
    node* GetRoot(); 
    void postorderTraversing(node *root);
    node* search(int data);
};
node* BST::search(int data)
{
    //we cant do recursion we have send root address and data again and again which is not good that's why we will run loop

    if(root)
    {
        node *t=root;
        while(t->item!=data)
        {
            if(data>root->item)
            {
                if()
            }
        }
        if(t->item==data)
            return t;
        return NULL; 
        

    }
}
void BST::postorderTraversing(node *root)
{
    if(root)
    {
        postorderTraversing(root->left);
        postorderTraversing(root->right);
        cout<<root->item<<" ";
    }
}
void BST::inorderTraversing(node *root)
{
    //inorder travesing gives you output in sorted order
    if(root)
    {
        inorderTraversing(root->left);
        cout<<root->item<<" ";
        inorderTraversing(root->right);
    }
}
node* BST::GetRoot()
{
    return root;
}
void BST::preorderTraversing(node *root)
{
    if(root)
    {
        cout<<root->item<<" ";
        preorderTraversing(root->left);
        preorderTraversing(root->right);
    }
}
void BST::insert(int data)
{
    node *n=new node;
    n->item=data;
    node *t=root;
    if(root)
    {
        while(n->item!=t->item)
        {
            if(data>t->item)
            {
                if(t->right!=NULL)
                    t=t->right;
                else
                {
                    t->right=n;
                    break;
                }
            }
            else
            {
                if(t->left!=NULL)
                    t=t->left;
                else
                {
                    t->left=n;
                    break;
                }
            }
        
        }
    }
    else
    root=n;
}
bool BST::isEmpty()
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
    b1.insert(7);
    b1.insert(9);
    b1.insert(5);
    b1.insert(4);
    b1.insert(1);
    b1.insert(2);
    b1.insert(6);
    b1.insert(8);
    b1.insert(10);
    b1.insert(22);
    b1.preorderTraversing(b1.GetRoot());
    cout<<endl;
    b1.inorderTraversing(b1.GetRoot());
    cout<<endl;
    b1.postorderTraversing(b1.GetRoot());
    cout<<endl;
    return 0;
}
#include<iostream>
using namespace std;

class node
{
    public:
    node *right;
    node *left;
    int item;
    node()
    {
        right=NULL;
        left=NULL;
    }
};

class BST
{
    private:
    node *root;
    protected:
    void preorderRec(node *r);
    public:
    BST();
    bool isTreeEmpty();
    void insert(int data);
    void preorderTraversing();
    node *GetRoot();
};
node *BST::GetRoot()
{
    return root;
}
void BST::preorderTraversing()
{
    preorderRec(root);
}
void BST::preorderRec(node *r)
{
    if(r)
    {
        cout<<r->item<<" ";
        preorderRec(r->left);
        preorderRec(r->right);
    }
}
void BST::insert(int data)
{
    node *n=new node;
    n->item=data;
    n->left=NULL;
    n->right=NULL;
    if(root)
    {
        node *t=root;
        while(t->item!=data)
        {
            if(t->item>data)
            {
                if(t->right!=NULL)
                    t=t->right;
                else
                    {
                        t->left=n;
                        break;
                    }
            }
            else
            {
                 if(t->left!=NULL)
                 {
                    t=t->left;
                 }
                else
                {
                    t->right=n;
                    break;
                }
                    
            }   
           
        }
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
    b1.preorderTraversing();
    b1.insert(11);
    b1.insert(15);
    b1.insert(16);
    b1.insert(13);
    b1.insert(17);
    b1.insert(44);
    b1.insert(1);
    b1.preorderTraversing();
    return 0;
}
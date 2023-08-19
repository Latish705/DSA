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
    void inorderTraversing(node *root);
    void postorderTraversing(node *root);
    void deleteElement(int data);

};
void BST::deleteElement(int data)
{
    if(root)
    {
        node *child=root;
        node *part=NULL;
        //thinking for no child to that for which element we are searching for
        while(!(child->left&&child->right)   && child->item!=data)
        {
                if(data>root->item)
                {
                    part=child;
                    child=child->right;
                    if(child->item==data)
                    {
                        part->right=NULL;
                        delete child;
                    }
                }
                else
                {
                    part=child;
                    child=child->left;
                    if(child->item==data)
                    {
                        part->left=NULL;
                        delete child;
                    }
                }
                
            }
        }
    }
void BST::postorderTraversing(node *root)
{
    if(root)
    {
        cout<<root->item<<" ";
        postorderTraversing(root->left);
        postorderTraversing(root->right);
    }
}
void BST::inorderTraversing(node *root)
{
    if(root)
    {
        inorderTraversing(root->left);
        cout<<root->item<<" ";
        inorderTraversing(root->right);
    }
}
node *BST::GetRoot()
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
    if(root)
    {
        node *t=root;
        while(n->item!=t->item)
        {
            if(n->item<t->item)
            {
                if(t->left!=NULL)
                    t=t->left;
                else
                {
                    t->left=n;
                    break;
                }
            }
            else
            {
                if(t->right!=NULL)
                    t=t->right;
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
    b1.preorderTraversing(b1.GetRoot());
    cout<<endl;
    b1.insert(11);
    b1.insert(15);
    b1.insert(16);
    b1.insert(17);
    b1.insert(13);
    b1.insert(44);
    b1.insert(1);
    b1.preorderTraversing(b1.GetRoot());
    cout<<endl;
    b1.inorderTraversing(b1.GetRoot());
    cout<<endl;
    b1.postorderTraversing(b1.GetRoot());
    cout<<endl;
    b1.deleteElement(13);
    cout<<endl;
    b1.inorderTraversing(b1.GetRoot());
    cout<<endl;
    BST b2;
    b2.insert(9);
    b2.insert(5);
    b2.insert(4);
    b2.insert(7);
    b2.insert(1);
    b2.insert(2);
    b2.insert(6);
    b2.insert(8);
    b2.insert(10);
    b2.insert(22);
    b2.preorderTraversing(b2.GetRoot());
    return 0;
}
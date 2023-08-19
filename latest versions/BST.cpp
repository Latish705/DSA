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
    void postorderRec(node *r);
    void inorderRec(node *r);
    void Recdellocate(node *r);
    public:
    BST();
    bool isTreeEmpty();
    void insert(int data);
    void preorderTraversing();
    node *GetRoot();
    void postorderTraversing();
    void inorderTraversing();
    node* search(int data);
    void Delete(int data);
    int traverseRight(node *t);
    ~BST();
};
int BST::traverseRight(node *t)
{
    node *n;
    while(t->left!=NULL&&t->right!=NULL)
    {
        if(t->right->right==NULL && t->right->left!=NULL)
        {
            Delete(t->item);
        }
        else
            t=t->right;
    }
    int c=t->item;
    delete t;
    return c;

}
void BST::Delete(int data)
{
    //this one is for just before
    node *tchild=root;
    node *tparent=root;
    while(tchild->item!=data)
    {   if(data==tchild->item)
        {
            break;
        }
        else if(data>tchild->item)
        {
            tparent=tchild;
            tchild=tchild->right;
        }
        else
        {
            tparent=tchild;
            tchild=tchild->left;
        }
    }
    if(data=tchild->item)
    {
        if(tchild->right&&tchild->left)
        {
            tchild->item=traverseRight(tchild->left);
        }
        else if((tchild->right==NULL&&tchild->left!=NULL))
        {
            tparent->right=tchild->right;
        }
        else if((tchild->left==NULL&&tchild->right!=NULL))
        {
            tparent->left=tchild->left;
        }
        else
        {
            tparent->left=NULL;
            tparent->right=NULL;
        }
    }

}
void BST::Recdellocate(node *r)
{
    if(r)
    {
        Recdellocate(r->left);
        delete r->left;
        Recdellocate(r->right);
        delete r->right;
        delete root;
    }
}
BST::~BST()
{
    Recdellocate(root);
}
node* BST::search(int data)
{
    //we cannot do recurrsion because we have to check data if we do recurrsion then we have to data every time we call fuction
    node *t=root;
    while(t)
    {
        if(t->item==data)
        {
            return t;
        }
        else if(data>root->item)
            t=t->right;
        else if(data<root->item)
            t=t->left;
    }
    cout<<"Element not found"<<endl;
    return t;

}
void BST::inorderTraversing()
{
    inorderRec(root);
}
void BST::inorderRec(node *r)
{
    if(r)
    {
        inorderRec(r->left);
        cout<<r->item<<" ";
        inorderRec(r->right);
    }
}
void BST::postorderRec(node *r)
{
    if(r)
    {
        postorderRec(r->left);
        postorderRec(r->right);
        cout<<r->item<<" ";
    }
}
void BST::postorderTraversing()
{
    postorderRec(root);
}
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
    cout<<endl;
    b1.postorderTraversing();
    cout<<endl;
    b1.inorderTraversing();
    cout<<endl;
    cout<<b1.search(55)->item<<endl;

    return 0;
}
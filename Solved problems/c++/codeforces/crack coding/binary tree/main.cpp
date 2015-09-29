#include <iostream>
#include<cstddef>
#include<stdlib.h>
using namespace std;

struct node{
node *left,*right;
int val;
};

class bst
{

public:
    node *root;
    bst()
    {
        root=NULL;
    }
    int isempty()
    {
        return root==NULL;
    }
    void print()
    {
        inorder(root);
    }
    int height()
    {
        checkheight(root);
    }
    bool isbalanced()
    {
        balanced(root);
    }
    bool checkbst()
    {
        checkbst(root,0,32000);
    }
    void insert(int x);
    void inorder(node *ptr);
    int checkheight(node *ptr);
    bool balanced(node*);
    bool checkbst(node*,int,int);

};
void bst::insert(int x)
{
    node *n=new node();
    node *parent;
        n->val=x;
        n->right=NULL;
        n->left=NULL;
    if(isempty())
    {
        root=n;
    }
    else{
        node *ptr=root;
        while(ptr!=NULL)
        {
            parent=ptr;
            if(x>ptr->val)
                ptr=ptr->right;
            else if(x<ptr->val)
                ptr=ptr->left;
            else{
                cout<<"The element "<<x<<" is already in the tree"<<endl;
            return;
            }
        }
        if(parent->val>x)
            parent->left=n;
        else
            parent->right=n;


    }
}
void bst::inorder(node *ptr)
{
    if(ptr==NULL)
        return;
    inorder(ptr->left);
    cout<<ptr->val<<endl;
    inorder(ptr->right);
}
int bst::checkheight(node *ptr)
{
   // int h=0;
    if(ptr==NULL)
        return 0;
   return (max(checkheight(ptr->left),checkheight(ptr->right))+1);
}
bool bst::balanced(node *ptr)
{
    int lh,rh,res;

    if(ptr==NULL)
        return 1;
    lh=checkheight(ptr->left);
    rh=checkheight(ptr->right);
    if(lh>rh)
        res=lh-rh;
    else
        res=rh-lh;

    if(res<=1&&balanced(ptr->left)&&balanced(ptr->right))
        return 1;

    return 0;

}
bool bst::checkbst(node *ptr,int min,int max)
{
    if(ptr==NULL)
        return 1;
    if(ptr->val<=min||ptr->val>max)
        return 0;
    if(!checkbst(ptr->left,min,ptr->val)||!checkbst(ptr->right,ptr->val,max))
        return 0;
    return 1;
}

int main()
{
    bst b;
    b.insert(10);
    b.insert(15);
    b.insert(11);
    b.insert(9);
    b.insert(10);

    b.print();
    cout<<"success"<<endl;
    int h=b.height();
    cout<<h<<endl;
    if(b.isbalanced())
        cout<<"BALANCED"<<endl;
    else
        cout<<"NOT BALANCED"<<endl;
    if(b.checkbst())
        cout<<"BST"<<endl;
    else
        cout<<"NOT BST"<<endl;
    return 0;
}

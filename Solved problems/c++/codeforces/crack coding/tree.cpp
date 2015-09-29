#include<iostream>
#include<cstddef>
#include<cstdlib>
using namespace std;

struct node
 {
node *left,*right;
int value;
};
class tree
{
 public:
      node *root=new node();
    tree():root(NULL)
    {

    }
    tree(int a)
    {
        insert(a,root);
    }
    void insert(int a,node *head)
    {
        if(root==NULL)
        {
            cout<<"5";
            node *n=new node;
            *n=*head;
            cout<<"6";
            cout<<a;
            n->value=a;
            cout<<a;
            n->left= NULL;

            n->right= NULL;
            n->value=a;
            cout<<a;
            return;
        }}
        /*
        if(a<head->value)
        {
            if(head!=NULL)
                insert(a,head->left);
        }
        else
            if(head!=NULL)
                insert(a,head->right);
    } */
    void print(node *head)
    {
        if(head==NULL)
            return;
        else
        {
            print(head->left);
            int a=head->value;
        cout<<a<<"\t";
        print(head->right);}
    }
};

int main()
{
    tree *t1=new tree();
    t1->insert(5,t1->root);

    return 0;
}


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
    void insert(int a,node &head)
    {
        if(root==NULL)
        {
            cout<<"5";

            cout<<"6";
            cout<<a;
            head->value=a;
            cout<<a;
            head->left= NULL;

            head->right= NULL;
            head->value=a;
            cout<<a;
            return;
        }}
};
int main()
{
    tree *t1=new tree();
    node *root=t1->root;
    t1->insert(5,root);

    return 0;
}


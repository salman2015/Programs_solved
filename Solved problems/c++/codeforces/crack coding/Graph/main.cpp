#include <iostream>
#include<list>

using namespace std;

struct node
{
    int val;
    node *next;
};

struct adjlist{
node *head;
};

class graph{
int v;
adjlist *array;
public:
    graph(int v)
    {
        this->v=v;
        array=new adjlist[v];
        for(int i=0;i<v;i++)
        {
            array[i].head=NULL;
        }
    }
    void addedge(int src,int dest);
    void print();
     bool haspath(int src,int dest);
    bool has_path(int src,int dest)
    {
        if(haspath(src,dest))
            cout<<src<<" -> "<<dest<<"---YES"<<endl;
        else
            cout<<src<<" -> "<<dest<<"---NO"<<endl;
    }
};

void graph::addedge(int src,int dest)
{
    node *n=new node();
    n->val=dest;
    n->next=array[src].head;
    array[src].head=n;
    cout<<"EDGE ADDED "<<src<<"  ->  "<<dest<<endl;

}

void graph::print()
{
    for(int i=0;i<v;i++)
    {
        cout<<"Adjacency list of vertex "<<i<<endl;
        node *ptr=array[i].head;
        while(ptr!=NULL)
        {
            cout<<ptr->val<<" --- ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
}
bool graph::haspath(int s,int d)
{
    if(s==d)
        return 1;
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    visited[s]=true;
    list<int> q;
    q.push_back(s);
    while(!q.empty())
    {
        int t=q.front();
        q.pop_front();
        node *ptr=array[t].head;
        while(ptr!=NULL)
        {
            int val=ptr->val;
            if(val==d)
                return true;
            if(!visited[val]){
            visited[val]=true;
            q.push_back(val);
            }
         ptr=ptr->next;
        }
    }
    return false;
}

int main()
{
    graph g1(5);
    g1.addedge(0,1);
    g1.addedge(1,2);
    g1.addedge(2,3);
    g1.addedge(3,2);
    g1.addedge(3,4);
    cout<<"-----------------------------------------------------------------PATH CHECK----------------------------------------------------"<<endl;
    g1.has_path(4,3);
    g1.has_path(0,4);
    cout<<"------------------------------------------------------------TREE ADJACENCY LIST------------------------------------------------"<<endl;
    g1.print();
}

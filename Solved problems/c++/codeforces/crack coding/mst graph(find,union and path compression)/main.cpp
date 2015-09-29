#include <iostream>
#include <queue>

using namespace std;


struct edge
{
    int src,dest;
    int w;
};
struct subset
{
   int parent;
   int rank;
};
class comparec
{
public:
    bool operator()(edge &e1,edge &e2)
    {
        return e1.w>e2.w;
    }
};

class graph
{
    int v,e;
    priority_queue < edge , vector<edge> ,comparec > pq;
    subset *subsets;
public:
    graph(int ver,int edg)
    {
        v=ver,e=edg;
        subsets=new subset[v];
        for(int i=0;i<v;i++)
        {
            subsets[i].parent=i;
            subsets[i].rank=0;
        }
    }
    ~graph()
    {
        delete subsets;
    }

    void kruskals(graph&);
    int findset(subset s1[],int i);
    void unions(subset s1[],int x,int y );
    void insert_edge(int src,int dest,int w);
};
void graph::insert_edge(int src,int dest,int w)
{
    edge e1;
    e1.src=src;
    e1.dest=dest;
    e1.w=w;
    pq.push(e1);
}
int graph::findset(subset subsets[],int i)
{
   if(subsets[i].parent==i)
        return i;
   subsets[i].parent=findset(subsets,subsets[i].parent);
}
void graph::unions(subset s1[],int x,int y)
{
 int xroot=findset(s1,x);
 int yroot=findset(s1,y);

 if(s1[xroot].rank>s1[yroot].rank)
    s1[yroot].parent=xroot;
 else if(s1[xroot].rank<s1[yroot].rank)
    s1[xroot].parent=yroot;
 else
 {
     s1[xroot].parent=yroot;
     s1[yroot].rank++;

 }
}
void graph::kruskals(graph &g1)
{
    int v=g1.v,e=0;
    while(e<v-1)
    {
        edge e1=pq.top();
        pq.pop();
        int src=findset(subsets,e1.src);
        int dest=findset(subsets,e1.dest);
        if(src==dest)
            continue;
        unions(subsets,src,dest);
        cout<<e1.src<<" - > " <<e1.dest<<endl;
        e++;

    }
}
int main()
{
    graph g1(4,5);
    g1.insert_edge(0,1,10);
    g1.insert_edge(1,3,15);
    g1.insert_edge(2,3,4);
    g1.insert_edge(2,0,6);
    g1.insert_edge(0,3,5);
    g1.kruskals(g1);
    return 0;
}

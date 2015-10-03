#include <iostream>
#include <list>
#include <limits.h>

using namespace std;

struct adjlist
{
    int v;
    int weight;
};

class graph
{
    int v;
    list<adjlist> *list1;
public:
    graph(int ver)
    {
        v=ver;
        list1=new list<adjlist>[v];
    }
    void insert_edge(int src,int dest,int w);
    void bellman(int src);
};
void graph::insert_edge(int src,int dest,int w)
{
    adjlist *node=new adjlist;
    node->v=dest;
    node->weight=w;
    list1[src].push_back(*node);
}
void graph::bellman(int src)
{

    int dist[v];
    for(int i=0;i<v;i++)
        dist[i]=INT_MAX;
    dist[src]=0;
    for(int i=0;i<v;i++)
    {
      list<adjlist>::iterator u;
      if(dist[i]!=INT_MAX)
      {
          for(u=list1[i].begin();u!=list1[i].end();u++ )
          {
              if(dist[i]+u->weight<dist[u->v])
              dist[u->v]=dist[i]+u->weight;

          }
      }
    }
    cout<<"vertex\t\t"<<"distance"<<endl;
    for(int i=0;i<v;i++)
    {
      cout<<i<<"\t\t"<<dist[i]<<endl;
    }
}

int main()
{
    graph g1(5);
    g1.insert_edge(0,1,-1);
    g1.insert_edge(0,2,4);
    g1.insert_edge(1,2,3);
    g1.insert_edge(1,3,2);
    g1.insert_edge(3,1,1);
    g1.insert_edge(3,2,5);
    g1.insert_edge(1,4,2);
    g1.insert_edge(4,3,-3);
    g1.bellman(0);
    cout<<"salman"<<INT_MAX;
    return 0;
}


#include<iostream>
#include<queue>
#include<string>

using namespace std;

struct edge
{
int src,dest;
int w;
};

struct subset
{
    int rank;
    int parent;
};
class mycompare
{
public:
    bool operator()(edge &e1,edge &e2)
    {
        return e1.w>e2.w;
    }
};
class graph
{
    int v;
    priority_queue< edge , vector< edge > , mycompare > pq;
    subset *subsets;
public:
    graph(int ver)
    {
        v=ver;
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
    int findset(subset s1[],int i);
    void unions(subset s1[],int x,int y);
    void insert_edge(int x,int y,int w);
    void kruskals(graph&);

};
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
    else if(s1[yroot].rank>s1[xroot].rank)
        s1[xroot].parent=yroot;
    else{
        s1[xroot].parent=yroot;
        s1[yroot].rank++;
    }
}
void graph::insert_edge(int x,int y,int w)
{
    edge e1;
    e1.src=x;
    e1.dest=y;
    e1.w=w;
    pq.push(e1);
}
void graph::kruskals(graph &g1)
{
  int v=g1.v,e=0;
  long long int cost=0;
  while(e<v-1)
  {
      edge e1=pq.top();
      pq.pop();
      int src=findset(subsets,e1.src);
      int dest=findset(subsets,e1.dest);
      if(src==dest)
        continue;
      unions(subsets,src,dest);
      cost+=e1.w;
      e++;
  }
  cout<<cost<<endl;
  }
  int main()
  {
      int t;
      cin>>t;
      while(t--)
      {
          int v,j=0;
          cin>>v;
          graph g1(v);
          while(v--){
          string name;
          cin>>name;
          int neighbours;
          cin>>neighbours;
          for(int i=0;i<neighbours;i++)
          {
              int e,c;
              cin>>e>>c;
              g1.insert_edge(j,--e,c);
          }
          j++;
          }
          g1.kruskals(g1);
      }
  }

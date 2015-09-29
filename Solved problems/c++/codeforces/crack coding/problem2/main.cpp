#include<iostream>
#include<queue>

using namespace std;

class mycompare{
public:
    bool operator()(int &a,int &b){
    return a<b;
    }
};


int max1(long long int a[],int n)
{
    int maxm=0;
    priority_queue< int, vector<int>,mycompare> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(a[i]);
    }
    maxm=pq.top();
    return maxm;
}

int main()
{
  int n;
  cin>>n;
  long long int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  int i=0;
  while(i<n)
  {
  int rightmax=max1(a+i,n-i);
  if(rightmax>a[i])
    cout<<(rightmax-a[i])+1<<endl;
  else
    cout<<"0"<<endl;
  i++;
}
return 0;
}


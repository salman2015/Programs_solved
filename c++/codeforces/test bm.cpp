#include<iostream>
#include<vector>

using namespace std;

int main()
{
int n,m,k;
cin>>n>>m>>k;
vector<bool> my[m+1];
for(int i=0;i<m+1;i++)
{
int num;
cin>>num;
for(int j=1<<n;j>0;j=j/2)
{
k=(num&j)?1:0;
my[i].push_back(k);
}
}
for(int i=0;i<m+1;i++)
{
    for(vector<bool>::iterator it=my[i].begin();it!=my[i].end();it++)
    cout<<*it;
cout<<endl;
}
vector<bool> a=my[m];
for(vector<bool>::iterator it=a.begin();it!=a.end();it++)
    cout<<*it;

return 0;
}

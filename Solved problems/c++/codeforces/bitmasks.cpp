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
int te=(num&j)?1:0;
my[i].push_back(te);
}
}
vector<bool> a=my[m];
int sum=0;
for(int i=0;i<m;i++)
{
    int count=0;
    for(vector <bool>::iterator it=my[i].begin(),it1=a.begin();it!=my[i].end();it++,it1++)
    {
        if(*it==*it1)
            continue;
        else
            count=count+1;
        if(count>k)
            break;
           }
    if(count<=k)
        sum++;
}
cout<<sum;
return 0;

}

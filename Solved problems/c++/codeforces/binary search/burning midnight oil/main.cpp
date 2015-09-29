#include<iostream>
using namespace std;
long long int n;
int k;
int f(long long int v)
{
    long long int x=v;
    int k1=k;
    while(v/k1!=0)
    {
        x=x+v/k;
        k1=k1*k;
        if(x>=n)
            return 1;
    }
    return 0;
}
int binarysearch(long long int l,long long int r)
{
    while(l<r)
    {
        long long int mid=(l+r)/2;
        if(f(mid)==0)
            l=mid+1;
        else
            r=mid;
    }
    return l;
}
int main()
{
    cin>>n>>k;
    cout<<binarysearch(0,n);
}

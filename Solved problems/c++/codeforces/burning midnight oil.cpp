#include<iostream>
using namespace std;
long long int n;
int k;
int f(int v)
{
    int x=0;
    while(v/k!=0)
    {
        x=x+v/k;
        k=k*k;
        if(x>=n)
            return 1;
    }
    return 0;
}
int binarysearch(int l,int r)
{
    while(l<r)
    {
        int mid=(l+r)/2;
        if(f(mid)==1)
            r=mid-1;
        else
            l=mid+1;
    }
    return l;
}
int main()
{
    cin>>n>>k;
    cout<<binarysearch(0,n);
}

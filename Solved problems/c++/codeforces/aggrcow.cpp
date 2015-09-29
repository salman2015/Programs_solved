#include<iostream>
#include<algorithm>
using namespace std;
long long int s[100001];
int c,n;
int f(int x)
{
    long long int lastpos=s[0];
    int placed=1;
    for(int i=1;i<n;i++)
    {
        if((s[i]-lastpos)>=x)
        {
            placed++;
            if(c==placed)
                return 1;
        lastpos=s[i];
        }

    }
    return 0;
}
int binarysearch(int l,int r)
{
    while(l<r)
    {
        int mid=(l+r)/2;
        if(f(mid)==1)
           l=mid+1;
        else
           r=mid;
    }
    return l-1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        for(int i=0;i<n;i++)
            cin>>s[i];
        sort(s,s+n);
        int m=s[n-1];
        cout<<"\n"<<binarysearch(0,m);

    }

}

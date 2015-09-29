
#include<iostream>
using namespace std;
int binarysearch(int low,int high,int bnum,int s[]);
int binarysearch(int low,int high,int bnum,int s[])
{
    int index;
    if(low>high)
        index=-1;
    else{
    int mid=(low+high)/2;
    if(bnum==s[mid])
        index=mid+1;
    else if(bnum>[mid]&&bnum<s[mid+1])
        index=mid+2;
    else
        if(bnum<s[mid])
        index=binarysearch(low,mid-1,bnum,s);
    else
        index=binarysearch(mid+1,high,bnum,s);
    }
    return index;
}

int main()
{
    int n,m;
    cin>>n;
    int a[n],sum=0,s[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum=sum+a[i];
        s[i]=sum;
    }
    cin>>m;


   while(m--)
   {
       int num;
       cin>>num;
       cout<<binarysearch(0,n,num,s)<<endl;;

   }
   return 0;
}

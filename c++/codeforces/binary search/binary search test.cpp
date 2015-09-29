
#include<iostream>
#include<algorithm>
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
        index=mid-1;
    else
        if(bnum<s[mid])
        index=binarysearch(low,mid-1,bnum,s);
    else
        index=binarysearch(mid+1,high,bnum,s);
    }
    return index;
}
int int_cmp(const void *a, const void *b)
{
    const int *ia = (const int *)a; // casting pointer types
    const int *ib = (const int *)b;
    return *ia  - *ib;
	/* integer comparison: returns negative if b > a
	and positive if a > b */
}

int main()
{
    int n,m;
    cin>>n;
    int s[n],num;
    for(int i=0;i<n;i++)
        cin>>s[i];
    cout<<"ENTER KEY:";
    cin>>num;


    cout<<endl<<binarysearch(0,n,num,s);
   return 0;
}

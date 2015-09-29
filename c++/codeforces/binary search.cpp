#include<iostream>
using namespace std;
int binarysearch(int a[],int lo,int hi,int num);

int binarysearch(int a[],int lo,int hi,int num)
{
    int index;
     while(lo<=hi)
    {
    int mid=(hi+lo)/2;
    if(a[mid]==num)
     return mid+1;
    else
    {
    if(num>a[mid])
   return binarysearch(a,mid+1,hi,num);
    else
      return binarysearch(a,lo,mid-1,num);
    }
    }
return -1;
}
int main()
{
int a[]={15,25,50,72};
int num=0;
cout<<"Enter num";
cin>>num;
cout<<"\n"<<binarysearch(a,0,4,num);
return 0;

}

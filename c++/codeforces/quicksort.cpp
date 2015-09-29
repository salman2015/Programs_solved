#include<iostream>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[],int lo,int hi)
{
    int pivot=a[hi];
    int i=lo,j=hi-1;
    while(i<j)
    {
        if(a[i]<pivot)
            i++;
        if(a[j]>pivot)
            j--;
        if(a[i]>pivot&&a[j]<pivot)
            swap(&a[i],&a[j]);
    }
    swap(&a[i],&a[hi]);
     return i;
}
void quicksort(int a[],int lo,int hi)
{
    if(lo<hi)
    {
    int p=partition(a,lo,hi);
    quicksort(a,lo,p-1);
    quicksort(a,p-1,hi);
    }
}
int main()
{
    int myarray[]={10,1,12,5,20,15,78,81,50};
    quicksort(myarray,0,8);
    for(int i=0;i<=8;i++)
    {
        cout<<myarray[i]<<"\n";
    }
    return 0;
}

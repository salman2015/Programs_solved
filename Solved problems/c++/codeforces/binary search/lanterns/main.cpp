#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<iomanip>
using namespace std;
//int int_cmp(const void* a,const void* b)
//{
//    return *a-*b;
//}
int main()
{
    int nl,l;
    int lb,rb;
    cin>>nl>>l;
    int a[nl],dia=0;
    float maxd=0;
    for(int i=0;i<nl;i++)
        cin>>a[i];
        sort(a,a+nl);
        for(int i=1;i<nl;i++)
        {
            dia=a[i]-a[i-1];
            if(float(dia)>maxd)
                maxd=float(dia);

        }
        maxd=maxd/2;
        lb=a[0],rb=l-a[nl-1];
        if(float(lb)>maxd)
            maxd=float(lb);
        if(float(rb)>maxd)
            maxd=float(rb);
        printf("%.10f",maxd);
        return 0;

}

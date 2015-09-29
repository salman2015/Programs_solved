#include<iostream>
#include<cstdio>
inline int max(int a,int b)
{
return a>b?a:b;}
inline int min(int a,int b)
{
return a<b?a:b;}
int a,b;
int main()
{
scanf("%d%d",&a,&b);
printf("%d %d\n",min(a,b),(max(a,b)-min(a,b))/2);}

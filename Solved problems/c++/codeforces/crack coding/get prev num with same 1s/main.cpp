#include<iostream>

using namespace std;

int getprev(int n)
{
int c=n,c0=0,c1=0;
while(((c&1)==1)&&(c!=0))
{
    c1++;
    c=c>>1;
}
while((c&1)==0)
{
    c0++;
    c=c>>1;
}
if(c0+c1==0&&c1+c0==31)
    return -1;
int p=c0+c1;
n &= ~(1 << p); // Flip rightmost non-trailing zero
n &= ~((1<<p) - 1); // Clear all bits to the right of p
n |= (((1<<(c1+1))-1)<<(c0-1));
return n;
}

int main()
{
    int n;
    cin>>n;
    cout<<getprev(n);
}

#include<iostream>

using namespace std;

int max1(int a[],int n)
{
    int maxm=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>maxm)
            maxm=a[i];
    }
    return maxm;
}

int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  int i=0;
  while(i<n)
  {
  int rightmax=max1(a+i,n-i);
  if(rightmax>a[i])
    cout<<(rightmax-a[i]);
  else
    cout<<"0";
  i++;
}
return 0;
}


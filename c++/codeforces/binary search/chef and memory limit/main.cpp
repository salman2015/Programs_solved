#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
            long long int curr=a[0],alloc=a[0];
        for(int i=1;i<n;i++)
            {
              if(a[i]>curr)
              {
                  alloc=alloc+a[i]-curr;
                  curr=a[i];
              }
              else
              {
                  curr=a[i];
              }
            }
        cout<<alloc<<endl;
    }
    return 0;
}

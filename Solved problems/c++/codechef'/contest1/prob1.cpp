#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int s;
        long int count=0;
        cin>>s;
        count=sqrt(s);
        cout<<count<<endl;
    }
    return 0;
}

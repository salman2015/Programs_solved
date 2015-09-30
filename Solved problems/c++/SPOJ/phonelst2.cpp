#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string phonebook[n];
        for(int i=0;i<n;i++)
        {
         cin>>phonebook[i];
        }
        sort(phonebook,phonebook+n);
        int i=0,flag=0;
        for(int j=1;j<n;j++)
        {

            if(phonebook[i]==(phonebook[j].substr(0,phonebook[i].length())))
            {
                flag=1;
            }
            i++;
        }
        if(!flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

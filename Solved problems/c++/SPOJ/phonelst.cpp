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
        vector<string> phonebook;
        for(int i=0;i<n;i++)
        {
         string num;
         cin>>num;
         phonebook.push_back(num);
        }
        sort(phonebook.begin(),phonebook.end());
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
}

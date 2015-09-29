#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    bool flagAB=0,flagBA=0;
    cin>>s;
    for(int i=1;i<s.length();i++)
    {
        if(flagAB&&flagBA)
            break;
        if(s[i-1]=='A'&&s[i]=='B'&&flagAB==0)
        {
            i++;
            flagAB=1;}
        else if(s[i-1]=='B'&&s[i]=='A'&&flagBA==0)
        {
            i++;
            flagBA=1;}

    }
    if(flagAB&&flagBA)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

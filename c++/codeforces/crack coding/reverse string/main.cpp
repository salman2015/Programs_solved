#include <iostream>
#include<string>

using namespace std;

string rev(string&);

int main()
{
    string a;
    cin>>a;
    cout<<rev(a);
    cout<<"\n"<<a;
    return 0;
}
string rev(string &org)
{
    int len=org.length()-1;
    for(int i=0,j=len;i<j;j--,i++)
    {
        char temp=org[i];
        org[i]=org[j];
        org[j]=temp;
    }
return org;
}

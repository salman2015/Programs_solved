#include<iostream>
#include<string>
using namespace std;
bool check(string a)
{
int len=a.length();
bool ch[256];
for(int i=0;i<len;i++)
{
int val=a[i];
if(ch[val])
    return false;
ch[val]=true;
}
return true;
}
int main ()
{
string t;
cin>>t;
if(check(t))
  cout<<"true";
else
  cout<<"Not true";
return 0;
}

#include <iostream>
#include<string>
#include<sstream>
using namespace std;

string compressed(string s);

int main()
{
    string s;
    cout << "Enter the string" << endl;
    cin>>s;
    cout<<compressed(s);
    return 0;
}

string compressed(string s)
{
    int a[256]={0},count=0;
    for(int i=0;i<s.length();i++)
    {
        int val=s[i];
        if(a[val]==0)
            count++;
        a[val]++;
    }
    if(count>=s.length()/2)
        return s;
    else{
        string s1;
        for(int i=0;i<256;i++)
        {
          if(a[i]>0)
          {
              char c=char(i);
              int val=a[i];
              stringstream sr;
              sr<<c<<val;
              s1+=sr.str();

          }
        }
        return s1;
    }
}

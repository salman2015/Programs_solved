#include <iostream>

using namespace std;
bool check_anagram(string s1,string s2);

int main()
{
    string s1,s2;
    cout << "Enter two strings" << endl;
    cin>>s1>>s2;
    if(check_anagram(s1,s2))
        cout<<"Anagram";
    else
        cout<<"Not anagram";
    return 0;
}
bool check_anagram(string s1,string s2)
{
    int len1=s1.length(),len2=s2.length();
    int a[256]={0},b[256]={0};
    for(int i=0;i<len1;i++)
    {
        int val=s1[i];
        a[val]++;
    }
    for(int i=0;i<len2;i++)
    {
        int val=s2[i];
        b[val]++;
    }
    for(int i=0;i<256;i++)
    {
        if(a[i]!=b[i])
           return false;
    }
    return true;
}

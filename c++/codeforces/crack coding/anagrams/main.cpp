#include <iostream>
#include<algorithm>
#include<string>

using namespace std;
void check(string,string);

int main()
{
    string s1,s2;
    cout << "Enter two strings" << endl;
    cin>>s1>>s2;
    check(s1,s2);
    return 0;
}
void check(string s1,string s2)
{
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2)
        cout<<"Anagram"<<endl;
    else
        cout<<"Not anagram"<<endl;
}

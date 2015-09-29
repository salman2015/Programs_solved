#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct my
    {
    char ch;
    int count;
};

bool cmp(my lhs,my rhs)
    {
    if(lhs.count==rhs.count)
     return lhs.ch<rhs.ch;
     else
    return lhs.count>rhs.count;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--)
        {
        int n,k;
        cin>>n>>k;
        bool flag=false;
        my a[26]={{0}};

        for(int i=0;i<n;i++)
            {
            char letter;
            cin>>letter;
            int pos=letter-'a';
            a[pos].ch=letter;
            a[pos].count++;
        }
        sort(a,a+26,&cmp);

        for(int j=0;j<26;j++)
            {
            if(a[j].count<=k)
                break;
            cout<<a[j].ch;
            flag=true;
        }
        if(!flag)
            cout<<"NONE";
    }
    return 0;
}

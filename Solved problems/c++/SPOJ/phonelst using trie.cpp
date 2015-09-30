#include<iostream>
#include<string>

using namespace std;

struct trie
{
    int is_end;
    trie *next[10];
    trie()
    {
        for(int i=0;i<10;i++)
            next[i]=NULL;
        is_end=0;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        trie *head,*tail;
        head=new trie;
        int n,flag=1;
        cin>>n;
        while(n--)
        {
            string str;
          cin>>str;
          tail=head;
          if(flag)
          {
              for(int i=0;i<str.length();i++)
              {
               if(tail->is_end)
               {
                flag=0;
                break;
               }
                int a=str[i]-'0';
                if(tail->next[a]==NULL)
                {
                    tail->next[a]=new trie;
                }
                tail=tail->next[a];

              }
              tail->is_end=1;
            for(int i=0;i<10;i++)
            {
                if(tail->next[i])
                   {
                      flag=0;
                      break;
                   }
            }

          }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}

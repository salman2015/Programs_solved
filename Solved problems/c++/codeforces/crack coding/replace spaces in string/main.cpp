#include <iostream>

using namespace std;
void replacespace(char[],int leng);

int main()
{
    char str[]="how are you?";
    int len=sizeof(str);
    replacespace(str,len);
    for(int i=0;i<17;i++)
        cout<<str[i];

    return 0;

}
void replacespace(char str[],int leng)
{
    int scount=0;
    for(int i=0;i<leng;i++)
    {
        if(str[i]==' ')
            scount++;
    }
    int newl=leng+scount*2;
    int ll=newl;
    str[newl]='\0';
    for(int i=leng-1;i>=0;i--)
    {
        if(str[i]!=' ')
        {
            str[newl-1]=str[i];
            newl=newl-1;
        }
        else
        {
            str[newl-1]='0';
            str[newl-2]='2';
            str[newl-3]='%';
            newl=newl-3;
        }
    }
    for(int i=0;i<ll;i++)
        cout<<str[i];

}

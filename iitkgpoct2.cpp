#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int crr[300]={0};
bool fun(char a,char b)
{
    return crr[(int)a]>crr[(int)b];
}
int main()
{
    int i,t,j,n,k;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        char c[26];
        for(j=0;j<26;j++)
        {
            c[j]='a'+j;
            crr[(int)c[j]]=0;
        }
        cin>>n;
        for(j=0;j<n;j++)
        {
            int drr[300]={0};
            cin>>s;
            for(k=0;k<s.length();k++)
            {
                if(drr[(int)s[k]]==0)
                    crr[(int)s[k]]++;
                drr[(int)s[k]]=1;
            }
        }
        sort(c,c+26,fun);
        char mini=c[0];
        for(j=0;j<26;j++)
        {
            if(crr[c[j]]==crr[c[0]])
            {
                if(c[j]<mini)
                    mini=c[j];
            }
            else
                break;
        }
        cout<<mini<<"\n";
    }
    return 0;
}

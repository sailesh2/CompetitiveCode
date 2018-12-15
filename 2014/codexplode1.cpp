#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,t,j;
    string s;
    cin>>t;
    long long int p;
    for(i=0;i<t;i++)
    {
        cin>>s;
        p=1;
        int has[300]={0};
        for(j=0;j<s.length();j++)
        {
            if(has[s[j]]>0)
            {
                p=((p%1000000007)*((j-(has[(int)s[j]]-1))%1000000007))%1000000007;
            }
            has[(int)s[j]]=j+1;
        }
        cout<<p%1000000007<<"\n";
    }
    return 0;
}

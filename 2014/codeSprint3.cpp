#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,t,j,ctr;
    string s,s1;
    cin>>t;
    for(i=0;i<t;i++)
    {
        int has[300]={0};
        cin>>s;
        for(j=0;j<s.length();j++)
        {
            has[(int)s[j]]=1;
        }
        cin>>s1;
        ctr=0;
        for(j=0;j<s1.length();j++)
        {
            if(has[(int)s1[j]]==1)
            {
                ctr++;
                has[(int)s1[j]]=0;
            }
        }
        cout<<ctr<<"\n";
    }
    return 0;
}

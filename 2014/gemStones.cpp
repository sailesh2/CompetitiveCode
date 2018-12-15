#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,n,j,ctr=0;
    string s;
    int counter[200]={0};
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        int sav[200]={0};
        for(j=0;j<s.length();j++)
        {
          //  cout<<(int)s[j]<<"-";
            if(sav[(int)s[j]]==0)
            {
                sav[(int)s[j]]=1;
                counter[(int)s[j]]++;
            }
        }
    }
    for(i=0;i<200;i++)
    {
        if(counter[i]==n)
            ctr++;
    }
    cout<<ctr;
    return 0;
}

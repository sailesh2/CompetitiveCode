#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,n,j,c,v;
    cin>>n;
    string s,save="";
    int cnt=0,cntr=0;
    i=0;
    while(i<n)
    {
        cin>>s;
        v=0;
        c=0;
        j=0;
        if(cntr==0)
        {
            while(j<s.length())
            {
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='A' || s[j]=='E' || s[j]=='I' || s[j]=='O' || s[j]=='U')
                {
                    v=v+1;
                    c=0;
                }
                else
                {
                    c=c+1;
                    v=0;
                }
                if(v>=2)
                {
                    if(s[j]!=s[j-1])
                    {
                        cnt=1;
                        break;
                    }
                }
                if(c>=3)
                {
                    cnt=1;
                    break;
                }
                j=j+1;
            }
        }
        if(cntr==0 and cnt==1)
        {
            save=s;
            cntr=1;
        }
        i=i+1;
    }
    cout<<save;
    return 0;
}

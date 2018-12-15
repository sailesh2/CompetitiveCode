#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int n,p,i,cnt;
    char j;
    cin>>n>>p;
    string s;
    cin>>s;
    int has[300]={0};
    for(i=n-1;i>=0;i--)
    {
        cnt=0;
        if(i-1>=0)
        has[s[i-1]]=1;
        if(i-2>=0)
        has[s[i-2]]=1;
        j=s[i]+1;
        while(j<'a'+p)
        {
            if(has[j]==0)
            {
                s[i]=j;
                cnt=1;
                break;
            }
            j++;
        }
        if(cnt==1)
        {
            if(i-1>=0)
            has[s[i-1]]=0;
            if(i-2>=0)
            has[s[i-2]]=0;
            i++;
            while(i<n)
            {
                if(i-1>=0)
                has[s[i-1]]=1;
                if(i-2>=0)
                has[s[i-2]]=1;
                j='a';

                while(j<'a'+p)
                {
                    if(has[j]==0)
                    {
                        s[i]=j;
                        break;
                    }
                    j++;
                }
                if(i-1>=0)
                has[s[i-1]]=0;
                if(i-2>=0)
                has[s[i-2]]=0;

                i++;
            }
            break;
        }
        if(i-1>=0)
        has[s[i-1]]=0;
        if(i-2>=0)
        has[s[i-2]]=0;
    }
    if(cnt==0)
    {
        cout<<"NO";
    }
    else
        cout<<s;
    return 0;
}

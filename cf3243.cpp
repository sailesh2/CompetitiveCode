#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    string s1,s2;
    cin>>s1>>s2;
    char s3[n];
    int has[100005]={0};
    int i,ctr=0;
    for(i=0;i<n;i++)
    {
        if(s1[i]==s2[i])
        {
            s3[i]=s1[i];
            has[i]=1;
            ctr++;
        }
    }
    int free,rem=n-ctr,ctr1,ctr2,ctr3,ctr4;
    char j;
    if(rem>2*k)
        cout<<"-1";
    else
    {
        free=rem-k;
        ctr1=0;
        for(i=0;i<n;i++)
        {
            if(ctr1>=free)
                break;
            if(has[i]==0)
            {
                s3[i]=s1[i];
                has[i]=1;
                ctr1++;
            }
        }
        ctr2=0;
        for(i=0;i<n;i++)
        {
            if(ctr2>=free)
                break;
            if(has[i]==0)
            {
                s3[i]=s2[i];
                has[i]=1;
                ctr2++;
            }
        }
        for(i=0;i<n;i++)
        {
            if(has[i]==0)
            {
                for(j='a';j<='z';j++)
                {
                    if(s1[i]!=j && s2[i]!=j)
                    {
                        has[i]=1;
                        s3[i]=j;
                        break;
                    }
                }
            }
        }
        ctr3=0;ctr4=0;
        for(i=0;i<n;i++)
        {
            if(s3[i]!=s1[i])
                ctr3++;

        }
        int dif;
        ctr4=0;
        if(ctr3<k)
        {
            dif=k-ctr3;
            for(i=0;i<n;i++)
            {
                if(ctr4>=dif)
                    break;
                if(s1[i]==s2[i])
                {
                    if(s3[i]=='z')
                        s3[i]='a';
                    else
                        s3[i]=s3[i]++;
                    ctr4++;
                }
            }
        }
        ctr3=0;
        for(i=0;i<n;i++)
        {
            if(s3[i]!=s1[i])
                ctr3++;

        }
        if(ctr3<k)
            cout<<"-1";
        else
        {
            for(i=0;i<n;i++)
                cout<<s3[i];
        }
    }
    return 0;
}

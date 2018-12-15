#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

long long int a,b;
int mod=1000000007;
int dp[2005][2005];

long long int stressfree(long long int,long long int);
long long int stressfull(long long int,long long int);

int main()
{
    int i,t,j,k;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>s;
        a=0;
        b=0;
        j=0;
        while(s[j]!='-')
        {
            a=a*10+int(s[j])-48;
            j++;
        }
        j++;
        while(j<s.length())
        {
            b=b*10+int(s[j])-48;
            j++;
        }
        for(j=0;j<=a+1;j++)
        {
            for(k=0;k<=b+1;k++)
                dp[j][k]=-1;
        }
        cout<<"Case #"<<i+1<<": ";
        cout<<stressfree(0,0)<<" ";
        for(j=0;j<=a+1;j++)
        {
            for(k=0;k<=b+1;k++)
                dp[j][k]=-1;
        }
        cout<<stressfull(0,0)<<"\n";

    }
    return 0;
}
long long int stressfree(long long int a1,long long int b1)
{
    if(a1==a)
        return 1;
    if(a1>a || b1>b)
        return 0;
    long long int sm=0;
    if(a1-b1>=2 && b1<=b)
    {
        if(dp[a1][b1+1]==-1)
            sm=(sm+stressfree(a1,b1+1))%mod;
        else
            sm=sm+(dp[a1][b1+1])%mod;
    }
    if(dp[a+1][b1]==-1)
        sm=(sm+stressfree(a1+1,b1))%mod;
    else
        sm=(sm+dp[a1+1][b1])%mod;
    dp[a1][b1]=sm;
    return sm;
}
long long int stressfull(long long int a1,long long int b1)
{

    if(b1==b)
    {
        return 1;
    }
    if(a1>b1 || a1>a || b1>b)
    {
        return 0;
    }
    long long int sm=0;
    if(a1<b1 && b1<=b)
    {
        if(dp[a1+1][b1]==-1)
            sm=(sm+stressfull(a1+1,b1))%mod;
        else
            sm=sm+(dp[a1+1][b1])%mod;
    }
    if(dp[a1][b1+1]==-1)
        sm=(sm+stressfull(a1,b1+1))%mod;
    else
        sm=(sm+dp[a1][b1+1])%mod;
    dp[a1][b1]=sm;
    return sm;
}

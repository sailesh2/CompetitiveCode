#include<stdio.h>
#include<iostream>

using namespace std;

int n,m;
long long int dp[100][100];
int arr[100];
long long brr[100]={0};
int has[100]={0},already[100]={0};
long long int fun(int,int);

int main()
{
    int i,j,k;
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x,y,c;
    for(i=0;i<k;i++)
    {
        cin>>x>>y>>c;
        brr[x-1]=c;
        has[x-1]=y-1;
        brr[y-1]=c;
        has[y-1]=x-1;
    }
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
            dp[i][j]=-1;
    }
    cout<<fun(0,0);
    return 0;
}
long long int fun(int i,int ctr)
{
    if(i>=n || ctr==m)
        return 0;

    long long int a;
    if(already[has[i]]==1)
    {
        already[i]=1;
        if(i+1<n && ctr+1<m && dp[i+1][ctr+1]!=-1)
            a=dp[i+1][ctr+1]+brr[i]+arr[i];
        else
            a=fun(i+1,ctr+1)+brr[i]+arr[i];
        already[i]=0;
    }
    else
    {
        already[i]=1;
        if(i+1<n && ctr+1<m && dp[i+1][ctr+1]!=-1)
            a=dp[i+1][ctr+1]+arr[i];
        else
            a=fun(i+1,ctr+1)+arr[i];
        already[i]=0;
    }
    long long int b;
    if(i+1<n && dp[i+1][ctr]!=-1)
        b=dp[i+1][ctr];
    else
        b=fun(i+1,ctr);
    dp[i][ctr]=max(a,b);
    return dp[i][ctr];
}

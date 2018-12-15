#include<stdio.h>
#include<iostream>

using namespace std;

long long int n,m;
long long int arr[105][105]={0};
long long int dp[105][105][105];

long long int fun(long long int,long long int,long long int,long long int);
int main()
{
    long long int k,k1,i,j,r,c,l;
    cin>>n>>m>>k1;
    //long long int arr[101][101]={0};
    for(i=0;i<k1;i++)
    {
        cin>>r>>c;
        arr[r-1][c-1]=1;
    }
    for(i=0;i<=k1;i++)
    {
        for(j=0;j<101;j++)
        {
            for(k=0;k<101;k++)
            {
                for(l=0;l<101;l++)
                    dp[j][k][l]=-1;
            }
        }
       cout<<fun(i,0,0,0)%1000007<<" ";
    }
    return 0;
}
long long int fun(long long int counter,long long int ctr,long long int i,long long int j)
{
    long long int val1=0,val2=0;
    //cout<<i<<" "<<j<<"\n";
    if(i>=n || j>=m)
        return 0;
    if(arr[i][j]==1)
        ctr++;
    if(ctr>counter)
        return 0;
    if(i==n-1 && j==m-1)
    {
        if(ctr==counter)
            return 1;
        else
            return 0;
    }
    if(i+1<n && j<m)
    {
        if(dp[ctr][i+1][j]==-1)
        val1=fun(counter,ctr,i+1,j);
        else
        val1=dp[ctr][i+1][j];
    }
    if(i<n && j+1<m)
    {
        if(dp[ctr][i][j+1]==-1)
        val2=fun(counter,ctr,i,j+1);
        else
        val2=dp[ctr][i][j+1];
    }
    if(arr[i][j]==1)
        dp[ctr-1][i][j]=(val1+val2)%1000007;
    else
        dp[ctr][i][j]=(val1+val2)%1000007;
    return val1+val2;
}

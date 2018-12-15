#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


int n,m;
long long int dp[505][20001];
long long int fun(int,int,vector<int> *);

int main()
{
    int i,t,j,k;
    long long int sm;
    cin>>t;
    for(i=0;i<t;i++)
    {
        sm=0;
        cin>>n>>m;
        vector<int> arr[n+1];
        for(j=0;j<n-1;j++)
        {
            cin>>u>>v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        for(j=0;j<n+1;j++)
        {
            for(k=0;k<=m;k++)
                dp[j][k]=0;
        }
        for(j=1;j<=m;j++)
        {
            sm=(sm+fun(1,j,arr))%1000000007;
        }
        cout<<sm%1000000007;
    }
    return 0;
}
long long int fun(int p,int val,vector<int> *arr)
{
    int i,j;
    long long int sum,pr=1;
    for(i=0;i<arr[p].size();i++)
    {
        if(has[arr[p][i]]==0)
        {
            sum=0;
            for(j=1;val*j<=m;j++)
            {
                has[arr[p][i]]=1;
                if(dp[arr[p][i]][val*j]==-1)
                    sum=(sum+fun(arr[p][i],val*j,arr))%1000000007;
                else
                    sum=sum+(dp[arr[p][i]][val*j])%1000000007;
                has[arr[p][i]]=0;
            }
            pr=(pr*sum)%1000000007;
        }
    }
    dp[p][val]=pr;
    return pr;
}

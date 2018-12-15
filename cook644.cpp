#include<stdio.h>
#include<iostream>
#include<vector>

#define gc getchar


using namespace std;


void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc())
        {x = (x<<1) + (x<<3) + c - 48;}
}


int n,m;
long long int dp[505][20001];
long long int fun(int,int,vector<int> *,int *);

int main()
{
    int i,t,j,k,u,v;
    long long int sm;
    scanint(t);
    for(i=0;i<t;i++)
    {
        sm=0;
        scanint(n);
        scanint(m);

        vector<int> arr[n+1];
        int has[20001]={0};
        for(j=0;j<n-1;j++)
        {
            scanint(u);
            scanint(v);

            arr[u].push_back(v);
            arr[v].push_back(u);

        }
        for(j=0;j<n+1;j++)
        {
            for(k=0;k<=m;k++)
            {
                if(k*2>m)
                    dp[j][k]=1;
                else
                    dp[j][k]=-1;
            }
        }
        for(j=1;j<=m;j++)
        {
            has[1]=1;
            sm=(sm+fun(1,j,arr,has))%1000000007;
            has[1]=0;
        }
        printf("%lld\n",sm%1000000007);
    }
    return 0;
}
long long int fun(int p,int val,vector<int> *arr,int * has)
{

    if(val*2>m)
    {
        dp[p][val]=1;
        return 1;
    }
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
                    sum=(sum+fun(arr[p][i],val*j,arr,has))%1000000007;
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

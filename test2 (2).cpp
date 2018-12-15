#include<bits/stdc++.h>
#include<cmath>
#define mod 1000000007
#define ll long long
#define gc getchar
using namespace std;
ll input() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  ll ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
int a[102][102];
int b[102][102];
int dp[102][102];
int x=mod;
int f(int s,int n,bool visit[])
{
	if(s==n-1)
		return 0;
	int x=mod;
	for(int i=0;i<n;i++)
	{
		if(visit[i]==0)
		{
			visit[i]=true;
			x=min(x,f(i,n,visit)+b[s][i]);
			visit[i]=false;
		}
	}
	return x;
}
int main()
{
	int t,n,k,i,j;
	t=input();
	while(t--)
	{
		n=input();
		k=input();
		/*
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j]=input();
				dp[i][j]=-1;
			}
		}*/
		bool visit[n];
		for(i=0;i<n;i++)
		{
			visit[i]=0;
			for(j=0;j<n;j++)
			{
				b[i][j]=input();
			}
		}
		visit[0]=true;
		int x=f(0,n,visit);
		cout<<x<<endl;
	}
}

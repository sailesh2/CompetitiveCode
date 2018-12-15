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
int dp[102][2];
int x=mod;
pair<int,int> f(int s,int n,bool visit[])
{
    pair<int,int> p;
	if(s==n-1)
		return make_pair(0,0);
	int x=mod;
	int mini=mod,save=0;
	//if(dp[s][0]!=-1)
        //return make_pair(dp[s][0],dp[s][1]);
	for(int i=0;i<n;i++)
	{
		if(visit[i]==0)
		{
			visit[i]=true;
			p=f(i,n,visit);
			if(p.first+b[s][i]==mini)
            {
                if(p.second+a[s][i]<save)
                    save=p.second+a[s][i];
            }
            else if(p.first+b[s][i]<mini)
            {
                mini=p.first+b[s][i];
                save=p.second+a[s][i];
            }
			visit[i]=false;
		}
	}
	//dp[s][0]=mini;
	//dp[s][1]=save;
	return make_pair(mini,save);
}
int main()
{
	int t,n,k,i,j;
	t=input();
	while(t--)
	{
		n=input();
		k=input();

		for(i=0;i<n;i++)
		{
		    dp[i][0]=-1;
		    dp[i][1]=-1;
			for(j=0;j<n;j++)
			{
				a[i][j]=input();
			}
		}
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
		pair<int,int> x=f(0,n,visit);
		if(x.second>k)
            cout<<"-1\n";
        else
            cout<<x.first<<" "<<x.second<<endl;
	}
}

#include<bits/stdc++.h>
#include <iostream>
#include <string>
#define rep(i,j,k) for(i=j; i<k;i++)
#define ll long long
using namespace std;
inline long long int slib(long long int k,long long int m)
{
	long long int q,x,mod;
	mod=30*m;
	q=((a*(a+1)%mod)*((6*(a*a)%mod*a)%mod+(9 * a * a)%mod + (a)%mod -1)+mod)%mod;
	x=q/30;
	return x;
}
int main()
{
	int t;
	one=bigint(1);
	six=bigint(6);
	nine=bigint(9);
	long long int n,m,j=1,p,k,l;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&m);
		long long int s,q,mod;
		mod=30*m;
		s=0;
		j=1;
		int cnt=0;
		while(j<=n)
		{
			p=n/j;
			k=n/p;
			l=j-1;
			q=slib(k,m)-slib(l,m);
			s=(s+q*p)%mod;
			j=k+1;
		}
		cout<<s<<endl;
	}
}

#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
inline long long int slib(long long int a,long long int m)
{
	long long int q,x,mod;
	mod=30*m;
	q=(6*a*a*a*a*a + 15*a*a*a*a + 10*a*a*a - a)%mod;
	x=q/30;
	return x;
}
int main()
{
	int t;
	long long int n,m,j,p,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&m);
		long long int s,q;
		s=0;
		j=1;
		while(j<=n)
		{
			p=(long long int)floor((float)n/j);
			k=(long long int)floor((float)n/p);
			q=(slib(k,m)-slib(j-1,m));
			s=(s+q*p)%m;
			j=k+1;
		}
		cout<<s%m<<endl;
	}
}

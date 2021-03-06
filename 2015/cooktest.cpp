#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 20
#define MOD 1000000007

using namespace std;

typedef long long int lli;

char x[MAX], y[MAX];
int m;
lli dp[MAX];

lli f(char *s, int n, int i);
bool isHated(char *s);

int main()
{
	int n,t,i;
	char s[MAX];
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%s%s",&n,&m,x,y);
		dp[0] = 1;
		for(i=1;i<m;i++) dp[i] = (dp[i-1]*26)%MOD;
		for(i=m;i<=n;i++) {
			dp[i] = f(s, i-1, i-1);
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}

bool isHated(char *s)
{
	char temp;
	temp = s[m];
	s[m] = '\0';
	if(strcmp(x, s)<=0 && strcmp(s, y)<=0) {
		s[m] = temp;
		return true;
	}
	else {
		s[m] = temp;
		return false;
	}
}

lli f(char *s, int n, int i)
{
	lli ans = 0;
	if(i==-1) return 1;
	if(i>=n-m+2) {
		ans = (ans + 24*dp[i])%MOD;
		s[i] = 'A';
		ans = (ans + f(s, n, i-1))%MOD;
		s[i] = 'B';
		ans = (ans + f(s, n, i-1))%MOD;
	}
	else {
		ans = (ans + 24*dp[i])%MOD;
		s[i] = 'A';
		if(!isHated(s+i)) ans = (ans + f(s, n, i-1))%MOD;
		s[i] = 'B';
		if(!isHated(s+i)) ans = (ans + f(s, n, i-1))%MOD;
	}
	return ans;
}

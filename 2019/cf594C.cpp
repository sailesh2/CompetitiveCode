#include<bits/stdc++.h>

using namespace std;

long long int n,m;
long long int mod=1000000007;

long long int dp[100005];

void setup(){
    long long int x=max(m,n);
    for(long long int i=0;i<=x;i++)
        dp[i]=-1;
}

long long int steps(long long int index){
    if(index==0)
        return 1LL;

    if(index==1)
        return 1LL;

    long long int v;
    if(dp[index-2]==-1)
        v=steps(index-2);
    else
        v=dp[index-2];

    if(dp[index-1]==-1)
        v=(v+steps(index-1))%mod;
    else
        v=(v+dp[index-1])%mod;

    dp[index]=v;
    return v;
}

int main(){
    cin>>n>>m;
    setup();
    long long int v=2;
    if(n>1)
        v=(v+(2* ((steps(n)-1+mod)%mod) )%mod)%mod;
    if(m>1)
        v=(v+(2* ((steps(m)-1+mod)%mod) )%mod)%mod;
    cout<<v;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
long long int mod=1000000007;

long long int dp[1001][11];

void clearDP(long long int m,long long int n){
    for(long long int i=0;i<=m;i++){
        for(long long int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
}

long long int fun(long long int m, long long int n){
    if(m==1)
        return n;
    long long int s=0;
    for(long long int i=1;i<=n;i++){
        if(dp[m-1][i]==-1)
            s=(s+fun(m-1,i))%mod;
        else
            s=(s+dp[m-1][i])%mod;
    }
    dp[m][n]=s%mod;
    return s%mod;
}

int main(){
    long long int n,m;
    cin>>n>>m;
    clearDP(m,n);
    if(m==1)
        cout<<(n*(n+1))/2;
    else
        cout<<((2*fun(m,n))%mod+mod-1)%mod;
    return 0;
}

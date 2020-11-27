#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,m;
    long long int mod=1000000007;
    cin>>n>>m;
    long long int dp[m+1][n+1];
    for(long long int i=1;i<=n;i++)
        dp[1][i]=i;
    long long int s=0;
    for(long long int i=2;i<=m;i++){
        s=0;
        for(long long int j=1;j<=n;j++){
            s=(s+dp[i-1][j])%mod;
            dp[i][j]=s;
        }
    }
    s=0;
    long long int dp2[m+1][n+1];
    for(long long int i=1;i<=n;i++){
        s=(s+dp[m][i])%mod;
        dp2[1][i]=s;
    }

    for(long long int i=2;i<=m;i++){
        s=0;
        for(long long int j=1;j<=n;j++){
            s=(s+dp2[i-1][j])%mod;
            dp2[i][j]=s;
        }
    }

    cout<<dp2[m][n];
    return 0;
}

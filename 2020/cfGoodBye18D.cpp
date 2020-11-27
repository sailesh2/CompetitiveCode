#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long int mod = 998244353;

    long long int dp[n+1];
    dp[0]=1;
    long long int fac = 1;

    for(int i=1;i<=n;i++){
        fac = (fac*i)%mod;
        dp[i] = (((dp[i-1]*i)%mod + fac)%mod - i + mod)%mod;
    }

    cout<<dp[n];
}

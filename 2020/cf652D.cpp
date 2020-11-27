#include<bits/stdc++.h>

using namespace std;

long long int mod=1000000007;
long long int len = 2000005;
long long int dp[2000005];

void setup(){
    long long int dp1[len];
    long long int dp2[len];

    dp[0]=0;
    dp[1]=0;
    dp1[1]=0;
    dp2[1]=1;
    for(long long int i=2;i<len;i++){
        dp1[i]=dp2[i-1];
        dp2[i]=((2*dp1[i-1])%mod+dp2[i-1])%mod;
        dp[i]=(dp1[i]*4)%mod;
        if(i-3>=0)
            dp[i]=(dp[i]+dp[i-3])%mod;
    }
}

int main(){
    long long int t,n;
    cin>>t;
    setup();
    for(long long int i=0;i<t;i++){
        cin>>n;
        cout<<dp[n-1]<<"\n";
    }
    return 0;
}

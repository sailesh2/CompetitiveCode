#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,l,r;
    cin>>n>>l>>r;
    long long int mod = 1000000007;
    long long int dp[n+1][3];
    long long int zeros = r/3 - (l-1)/3;
    long long int ones =  r/3 - (l-1)/3;
    long long int twos =  r/3 - (l-1)/3;

    if(r%3==0){
        if((l-1)%3==1)
            ones--;
        else if((l-1)%3==2){
            ones--;
            twos--;
        }
    }
    else if(r%3==1){
        if((l-1)%3==0)
        ones++;
        if((l-1)%3==2)
        twos--;
    }
    else if(r%3==2){
        if((l-1)%3==0)
        ones++;
        if((l-1)%3==0 || (l-1)%3==1)
        twos++;
    }
    dp[1][0]=zeros;
    dp[1][1]=ones;
    dp[1][2]=twos;

    for(int i=2;i<=n;i++){
        dp[i][0] = ( ( (dp[i-1][0]*zeros)%mod + (dp[i-1][1]*twos)%mod )%mod + (dp[i-1][2]*ones)%mod)%mod;
        dp[i][1] = ( ( (dp[i-1][0]*ones)%mod + (dp[i-1][1]*zeros)%mod )%mod + (dp[i-1][2]*twos)%mod)%mod;
        dp[i][2] = ( ( (dp[i-1][0]*twos)%mod + (dp[i-1][1]*ones)%mod )%mod + (dp[i-1][2]*zeros)%mod)%mod;
    }
    cout<<dp[n][0];
    return 0;
}

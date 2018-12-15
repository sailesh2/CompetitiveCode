#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int dp[n][n];
    dp[0][0]=s[0];
    for(int i=1;i<n;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j]+s[i]-k*(i-j-1)*(i-j-1));
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}

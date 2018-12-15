#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int mod=1000000007;
    int n=s.length();
    int dp[1001][101]={0};

    for(int i=0;i<n;i++)
        dp[i][i]=1;
    int j;
    for(int c=2;c<=n;c++){
        for(int i=0;i<n-c+1;i++){
            j=i+c-1;
            dp[i][j]=(dp[i+1][j]+dp[i][j-1])%mod;
            if(s[i]==s[j]){
                dp[i][j]=(dp[i][j]+1)%mod;
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}

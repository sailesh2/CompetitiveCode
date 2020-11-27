#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,m;
    string s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        cin>>s;
        int p[m];
        for(int j=0;j<m;j++){
            cin>>p[j];
        }
        int dp[n][26];
        for(int j=0;j<n;j++){
            for(int k=0;k<26;k++)
                dp[j][k]=(j==0?0:dp[j-1][k]);

            dp[j][s[j]-'a']++;
        }
        int ans[26]={0};
        for(int j=0;j<m;j++){
            for(int k=0;k<26;k++){
                ans[k]=ans[k]+dp[p[j]-1][k];
            }
        }
        for(int k=0;k<26;k++){
            ans[k]=ans[k]+dp[n-1][k];
        }
        for(int j=0;j<26;j++)
            cout<<ans[j]<<" ";
        cout<<"\n";
    }
    return 0;
}

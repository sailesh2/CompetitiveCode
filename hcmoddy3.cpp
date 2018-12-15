#include<bits/stdc++.h>

using namespace std;
int n,m,k;
int mod=1000000007;
int dp[10002][1002];
void clearDP(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
}
int dpPartition(int len,int parts){
    if(len==0){
        dp[len][parts]=1;
        return 1;
    }
    if(parts==0){
        dp[len][parts]=0;
        return 0;
    }
    if(parts*k<len){
        dp[len][parts]=0;
        return 0;
    }
    if(parts*k==len){
        dp[len][parts]=1;
        return 1;
    }
    if(parts==1){
        if(len<=k){
            dp[len][parts]=1;
            return 1;
        }else{
            dp[len][parts]=0;
            return 0;
        }
    }
    long long int a=0;
    for(int i=0;i<=k;i++){
        if(len-i<0)
            break;
        if(dp[len-i][parts-1]!=-1)
            a=(a+dp[len-i][parts-1])%mod;
        else
            a=(a+dpPartition(len-i,parts-1))%mod;
    }
    dp[len][parts]=a;
    return a;
}
int main(){
    cin>>n>>m>>k;
    clearDP();
    cout<<dpPartition(n,m)%mod;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
long long int dp[5001][5001]={0};
int mod=998244353;

long long int cal(int n,int m){
    if(n<=0 || m<=0)
        return 1;

    long long int s=0;
    if(n-1>=0 && dp[n-1][m]>0){
        s=(s+dp[n-1][m])%mod;
    }else{
        s=(s+cal(n-1,m))%mod;
    }

    if(n-1>=0 && m-1>=0 && dp[n-1][m-1]>0){
        s=(s+(m*dp[n-1][m-1])%mod)%mod;
    }else{
        s=(s+(m*cal(n-1,m-1))%mod)%mod;
    }
    dp[n][m]=s;
    return s;
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    long long int sab=cal(a,b);
//    resetDP();
    long long int sac=cal(a,c);
//    resetDP();
    long long int sbc=cal(b,c);
    cout<<(sab*((sac*sbc)%mod))%mod;
    return 0;
}

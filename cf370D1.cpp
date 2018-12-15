#include<stdio.h>
#include<iostream>

using namespace std;

int k,mod=1000000007;
long long int dp[1000000][105]={0};
long long int game(int,int,int);
int main(){
    int a,b;
    cin>>a>>b>>k;
    cout<<game(a,b,1);
}

long long int game(int a,int b,int t){
    if(t==k){
        return a>b ? 1:0;
    }

    long long int sm=0;
    for(int i=-1*k;i<=k;i++){
        for(int j=-1*k;j<=k;j++){
            if(dp[a+i-b-j][t+1]!=0)
                sm=(sm+dp[a+i-b-j][t+1])%mod;
            else
                sm=(sm+game(a+i,b+j,t+1))%mod;
        }
    }

    dp[a-b][t]=sm;
    return sm;
}

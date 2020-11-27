#include<bits/stdc++.h>

using namespace std;
long long int n,m;
set<pair<string,string>> mp;
long long int mod=1000000007;
long long int dp[11][1001][1001];

void clearDP(){
    for(long long int i=0;i<=m;i++){
        for(long long int j=0;j<=n;j++){
            for(long long int k=0;k<=n;k++)
                dp[i][j][k]=-1;
        }
    }
}

long long int fun(long long int index, long long int vala, long long int valb){
    long long int s=0;
    if(index==m-1){

    //cout<<index<<"=="<<vala<<"=="<<valb<<"\n";
        return 1;
    }

    for(long long int i=vala;i<=n;i++){
        for(long long int j=valb;j>=1;j--){
            if(i<=j){
                if(dp[index+1][i][j]==-1)
                    s=(s+fun(index+1,i,j))%mod;
                else
                    s=(s+dp[index+1][i][j])%mod;

            }else
            break;
        }
    }
    dp[index][vala][valb]=s;
    return s;
}

int main(){
    cin>>n>>m;
    long long int s=0;
    clearDP();
    for(long long int i=1;i<=n;i++){
        for(long long int j=n;j>=1;j--){
            if(i<=j){
                if(dp[0][i][j]==-1)
                    s=(s+fun(0,i,j))%mod;
                else
                    s=(s+dp[0][i][j])%mod;
            }else
            break;
        }
    }
    cout<<s;
    return 0;
}

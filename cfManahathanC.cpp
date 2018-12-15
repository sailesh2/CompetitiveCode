#include<bits/stdc++.h>

using namespace std;

int n,m,k,x,mod=1000000007;

vector<int> tree[1000005];
int type[1000005]={0};
int has2[1000005]={0};
int dp[1000005][11];

void clearHas2(){
    for(int i=0;i<=n;i++){
        has2[i]=0;
    }
}
void resetDP(){
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<11;j++){
            dp[i][j]=-1;
        }
    }
}
long long int countWays(int ind,int types){
    int next;
    long long int p=1;
    int cnt=0;
    for(int i=0;i<tree[ind].size();i++){
        next=tree[ind][i];
        if(has2[next]==0){

//        cout<<next<<"\n";
            has2[next]=1;
            if(type[next]==1){
                cnt=1;
            }
            p=(p*countWays(next,type[ind]))%mod;
            has2[next]=0;

//        cout<<"p"<<p<<"\n";
        }
    }
    if(type[ind]==0){
        if(cnt==1 || types==1){
            p=(p*(k-1))%mod;
        } else{
            p=(p*(m-1))%mod;
        }
    } else{
        if(cnt==1 || types==1){
            return 0;
        }
    }
    return p;
}

long long int vaultWaysDP(int ind,int typesCovered){
    long long int c=0;
    if(ind==n+1){
        clearHas2();
        has2[1]=1;
        c=countWays(1,0)%mod;
        has2[1]=0;
        dp[ind][typesCovered]=c;
        return c;
    }
    type[ind]=0;
    if(dp[ind+1][typesCovered]==-1)
        c=(c+vaultWaysDP(ind+1,typesCovered))%mod;
    else
        c=(c+dp[ind+1][typesCovered])%mod;
    if(typesCovered<x){
        type[ind]=1;
        if(dp[ind+1][typesCovered+1]==-1)
            c=(c+vaultWaysDP(ind+1,typesCovered+1))%mod;
        else
            c=(c+dp[ind+1][typesCovered+1])%mod;
    }
    dp[ind][typesCovered]=c;
    return c;
}

int main(){
    int u,v;
    cin>>n>>m;


    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cin>>k>>x;
    resetDP();
    cout<<vaultWaysDP(1,0);

    return 0;
}

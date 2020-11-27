#include<bits/stdc++.h>

using namespace std;

long long int n,k;
long long int kn[300];
long long int kn1[300];
long long int ncr[300][300];
long long int powM[300];
long long int mod=1000000007;
long long int dp[300][300];

void clearDP(){
    for(long long int i=0;i<=n;i++){
        for(long long int j=0;j<=n;j++)
            dp[i][j]=-1;
    }
}

long long int fastPower(long long int a, long long int b){
    vector<int> bin;
    while(b>0){
        bin.push_back(b%2);
        b=b/2;
    }

    long long int ans=1,p=a;
    for(int i=0;i<bin.size();i++){
        if(bin[i]==1){
            ans=(ans*p)%mod;
        }
        p=(p*p)%mod;
    }

    return ans;
}

void setup(){
    kn[0]=1;

    for(long long int i=1;i<=n;i++){
        kn[i]=(kn[i-1]*k)%mod;
    }

    kn1[0]=1;

    for(long long int i=1;i<=n;i++){
        kn1[i]=(kn1[i-1]*(k-1))%mod;
    }

    for(long long int i=0;i<=n;i++){

        powM[i]=fastPower(i,mod-2);
    }

    for(long long int i=1;i<=n;i++){
        long long int facN=1;
        long long int facD=1;
        long long int ctr=0;
        ncr[i][ctr]=1;
        while(ctr<i){
            facN=(facN*(i-ctr))%mod;
            ctr++;
            facD=(facD*powM[ctr])%mod;

            ncr[i][ctr]=(facN*facD)%mod;
        }
    }

}

long long int validGrids(long long int index, long long int rem){


    if(index==n){
        return 1;
    }

    if(rem==n){
        return ((kn[n]-1+mod)%mod * validGrids(index+1,rem))%mod;
    }

    long long int val=0;
    for(long long int i=1;i<=n-rem;i++){
        long long int validGrid;
        if(dp[index+1][rem+i]==-1)
            validGrid = validGrids(index+1,rem+i);
        else
            validGrid = dp[index+1][rem+i];
        val=(val + ( ( ((ncr[n-rem][i]*validGrid)%mod) * kn1[n-rem-i])%mod * kn[rem])%mod)%mod;
    }

    dp[index][rem]=val;
    return val;
}

int main(){
    cin>>n>>k;
    clearDP();
    setup();
    cout<<validGrids(0,0);
    return 0;
}

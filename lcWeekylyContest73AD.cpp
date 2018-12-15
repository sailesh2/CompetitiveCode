#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int mod=1000000007;
    int dp[2000][2];

    void preprocess(int N){
        for(int i=0;i<=N+5;i++){
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
    }

    int numTilingsDP(int ind,int cnt,int N){
        if(ind==N){
            return 1-cnt;
        }
        if(ind>N){
            return 0;
        }
        int a=0;
        if(cnt==0){
            if(dp[ind+1][0]==-1)
                a=(a+numTilingsDP(ind+1,0,N))%mod;
            else
                a=(a+dp[ind+1][0])%mod;
            if(dp[ind+2][0]==-1)
                a=(a+numTilingsDP(ind+2,0,N))%mod;
            else
                a=(a+dp[ind+2][0])%mod;
            if(dp[ind+1][1]==-1)
                a=(a+2*numTilingsDP(ind+1,1,N))%mod;
            else
                a=(a+(2*dp[ind+1][1])%mod)%mod;
        }else{
            if(dp[ind+2][0]==-1)
                a=(a+numTilingsDP(ind+2,0,N))%mod;
            else
                a=(a+dp[ind+2][0])%mod;
            if(dp[ind+1][1]==-1)
                a=(a+numTilingsDP(ind+1,1,N))%mod;
            else
                a=(a+dp[ind+1][1])%mod;
        }
        dp[ind][cnt]=a;
        return a;
    }
public:
    int numTilings(int N) {
        preprocess(N);
        return numTilingsDP(0,0,N);
    }
};

int main(){
    Solution sol;
    cout<<sol.numTilings(1);
}

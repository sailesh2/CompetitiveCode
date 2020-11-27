class Solution {
private:
    int nt,mt,kt;
    int mod = 1000000007;
    int dp[51][101][51];

    void clearDP(){
        for(int i=0;i<=nt;i++){
            for(int j=0;j<=mt;j++){
                for(int k=0;k<=kt;k++)
                    dp[i][j][k]=-1;
            }
        }
    }

    int numArr(int index,int maxi,int k){
        if(index==nt){
            return k==0?1:0;
        }

        int ways=0;
        if(k>0){
            for(int i=maxi+1;i<=mt;i++){
                if(dp[index+1][i][k-1]==-1)
                    ways=(ways+numArr(index+1,i,k-1))%mod;
                else
                    ways=(ways+dp[index+1][i][k-1])%mod;
            }
        }

        for(int i=1;i<=maxi;i++){
            if(dp[index+1][maxi][k]==-1)
                ways=(ways+numArr(index+1,maxi,k))%mod;
            else
                ways=(ways+dp[index+1][maxi][k])%mod;
        }

        dp[index][maxi][k]=ways;
        return ways;
    }
public:
    int numOfArrays(int n, int m, int k) {
        nt=n;
        mt=m;
        kt=k;
        clearDP();
        return numArr(0,0,k);
    }
};

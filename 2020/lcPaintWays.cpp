class Solution {
private:
    int dp[5001][3][3][3];
    int n;
    int mod=1000000007;

    void clearDP(){
        for(int i=0;i<=n;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++)
                        dp[i][j][k][l]=-1;
                }
            }
        }
    }

    int paintWays(int index, int f, int s, int t){
        if(index==n)
            return 1;

        int c=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(i!=f && j!=s && k!=t && i!=j && j!=k){
                        if(dp[index+1][i][j][k]==-1)
                            c=(c+paintWays(index+1, i, j , k))%mod;
                        else
                            c=(c+dp[index+1][i][j][k])%mod;
                    }
                }
            }
        }

        if(f!=-1)
            dp[index][f][s][t]=c;
        return c;
    }
public:
    int numOfWays(int n1) {
        n=n1;
        clearDP();
        return paintWays(0,-1,-1,-1);
    }
};

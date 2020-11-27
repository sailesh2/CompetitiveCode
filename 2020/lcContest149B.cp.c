class Solution {
    int dp[35][1005];
    int mod=1000000007;
    void clearDP(int d, int target){
        for(int i=0;i<=d;i++){
            for(int j=0;j<=target;j++){
                dp[i][j]=-1;
            }
        }
    }

    int numRollsDP(int d, int f, int target){
        if(target==0 && d==0)
            return 1;

        int v=0;
        for(int i=1;i<=f;i++){
            if(target-i>=0 && d-1>=0){
                if(dp[d-1][target-i]!=-1)
                    v=(v+dp[d-1][target-i])%mod;
                else
                    v=(v+numRollsDP(d-1,f,target-i))%mod;
            }
        }

        dp[d][target]=v;
        return v;
    }
public:
    int numRollsToTarget(int d, int f, int target) {
        clearDP(d,target);
        return numRollsDP(d,f,target);
    }
};

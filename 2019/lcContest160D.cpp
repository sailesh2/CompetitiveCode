class Solution {
private:
    int dp[14][14];
    int MAX=1000000000;
    void clearDP(){
        for(int i=0;i<14;i++){
            for(int j=0;j<14;j++)
                dp[i][j]=-1;
        }
    }

    int tilRect(int n, int m){
        if(n==1 || m==1)
            return max(n,m);

        int mini=min(n,m);
        int ans=MAX;
        for(int i=1;i<=mini;i++){
            int v=0;
            if(n-mini>0){
                if(dp[n-mini][m]==-1)
                    v=v+tilRect(n-mini,m);
                else
                    v=v+dp[n-mini][m];
            }
            if(m-mini>0){
                if(dp[n][m-mini]==-1)
                    v=v+tilRect(n,m-mini);
                else
                    v=v+dp[n][m-mini];
            }
            ans=min(ans,v);
        }

        dp[n][m]=ans;
        return ans;
    }
public:
    int tilingRectangle(int n, int m) {
        clearDP();
        return tilRect(n,m);
    }
};

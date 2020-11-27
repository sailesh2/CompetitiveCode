class Solution {
private:
    int dp[10000][2];

    void preProcess(int n){
        for(int i=0;i<=n+1;i++){
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
    }

    bool game(int n,int cnt){
        if(n==1){
            dp[n][cnt]=1;
            return false;
        }
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(dp[n-i][1-cnt]==-1){
                    if(!game(n-i,1-cnt)){
                        dp[n][cnt]=0;
                        return true;
                    }
                }else{
                    if(dp[n-i][1-cnt]==1){
                        dp[n][cnt]=0;
                        return true;
                    }
                }
                if(i>1){
                if(dp[n-n/i][1-cnt]==-1){
                    if(!game(n-n/i,1-cnt)){
                        dp[n][cnt]=0;
                        return true;
                    }
                }else{
                    if(dp[n-n/i][1-cnt]==1){
                        dp[n][1-cnt]=0;
                        return true;
                    }
                }
                }
            }
        }
        dp[n][1-cnt]=1;
        return false;
    }
public:
    bool divisorGame(int N) {
        preProcess(N);
        return game(N,0);
    }
};

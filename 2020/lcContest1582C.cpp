class Solution {
private:
    int tot;
    vector<int> rolls;
    int dp[5005][6][16];
    int mod=1000000007;

    void clearDP(){
        for(int i=0;i<=tot;i++){
            for(int j=0;j<6;j++){
                for(int k=0;k<16;k++)
                    dp[i][j][k]=-1;
            }
        }
    }

    int dieSimDP(int rollIndex, int prevRoll, int cnt){
        if(rollIndex==tot)
            return 1;
        int v=0;
        for(int i=0;i<6;i++){
            if(prevRoll!=i){
                if(dp[rollIndex+1][i][1]==-1)
                    v=(v+dieSimDP(rollIndex+1,i,1))%mod;
                else
                    v=(v+dp[rollIndex+1][i][1])%mod;
            }


            if(prevRoll==i && cnt<rolls[i]){
                if(dp[rollIndex+1][i][cnt+1]==-1)
                    v=(v+dieSimDP(rollIndex+1,i,cnt+1))%mod;
                else
                    v=(v+dp[rollIndex+1][i][cnt+1])%mod;
            }


//cout<<"p"<<prevRoll<<"- "<<i<<" "<<v<<"\n";

        }

        if(prevRoll!=-1)
        dp[rollIndex][prevRoll][cnt]=v;
        return v;
    }
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        tot=n;
        rolls=rollMax;
        clearDP();
        return dieSimDP(0,-1,0);
    }
};

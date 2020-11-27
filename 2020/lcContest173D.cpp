class Solution {
private:
    int dp[301][11];
    int n;
    int MAX=1000000000;
    vector<int> jobs;
    void clearDP(){
        n=jobs.size();
        for(int i=0;i<301;i++){
            for(int j=0;j<11;j++)
                dp[i][j]=-2;
        }
    }

    int minDif(int index, int d){
        if(index>=n){
            if(d>0)
                return -1;
            return 0;
        }
        if(n-index<d){
            dp[index][d]=-1;
            return -1;
        }
        int maxi=0;
        if(d==0){
            for(int i=index;i<n;i++){
                maxi=max(maxi,jobs[i]);
            }
            dp[index][d]=maxi;
            return maxi;
        }
        int mini=MAX;
        int v;
        for(int i=index;i<n;i++){
            maxi=max(maxi,jobs[i]);
            if(dp[i+1][d-1]==-2){
                v=minDif(i+1,d-1);
            }else{
                v=dp[i+1][d-1];
            }
            if(v!=-1){
                mini=min(mini,maxi+v);
            }
        }
        if(mini==MAX)
            mini=-1;
        dp[index][d]=mini;
        return mini;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        jobs=jobDifficulty;
        clearDP();
        return minDif(0, d);
    }
};

class Solution {
private:
    int n;
    int dp[501][501];

    void clearDP(){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        }
    }

    int maxSatisfy(int index, int ctr, vector<int>& satisfaction){

        if(index==n)
            return 0;

        int a;
        if(dp[index+1][ctr+1]==-1)
            a=satisfaction[index]*(ctr+1) + maxSatisfy(index+1,ctr+1,satisfaction);
        else
            a=satisfaction[index]*(ctr+1) + dp[index+1][ctr+1];

        if(dp[index+1][ctr]==-1)
            a=max(a,maxSatisfy(index+1,ctr,satisfaction));
        else
            a=max(a,dp[index+1][ctr]);

        dp[index][ctr]=a;
        return a;
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        n=satisfaction.size();
        clearDP();
        return maxSatisfy(0, 0, satisfaction);
    }
};

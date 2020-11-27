class Solution {
private:
    vector<int> c;
    int dp[366][400][3];

    void clearDP(){
        for(int i=0;i<366;i++){
            for(int j=0;j<400;j++){
                for(int k=0;k<3;k++)
                    dp[i][j][k]=-1;
            }
        }
    }

    int minCostT(int ind, int remday, int taken, vector<int>& days){
        if(ind>=days.size()){
            return 0;
        }
        int v=1000000000;
        if(remday>=days[ind]){
            if(dp[ind+1][remday][taken]==-1)
            v=minCostT(ind+1,remday,taken,days);
            else
            v=dp[ind+1][remday][taken];
        }
        if(dp[ind+1][days[ind]][0]==-1)
        v=min(v,minCostT(ind+1,days[ind],0,days) + c[0]);
        else
        v=min(v,dp[ind+1][days[ind]][0] + c[0]);

        if(dp[ind+1][days[ind] + 6][1]==-1)
        v=min(v,minCostT(ind+1,days[ind] + 6,1,days) + c[1]);
        else
        v=min(v,dp[ind+1][days[ind] + 6][1] + c[1]);

        if(dp[ind+1][days[ind] + 29][2]==-1)
        v=min(v,minCostT(ind+1,days[ind] + 29,2,days) + c[2]);
        else
        v=min(v,dp[ind+1][days[ind] + 29][2] + c[2]);

        dp[ind][remday][taken]=v;
        return v;
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        c=costs;
        clearDP();
        return minCostT(0,0,0,days);
    }
};

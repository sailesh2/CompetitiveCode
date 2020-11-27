class Solution {
private:
    int m;
    int n;
    vector<vector<int>> cost;
    int dp[105][21][105];
    int MAX = 1000000007;

    void clearDP(){
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=m;k++)
                    dp[i][j][k]=-1;
            }
        }
    }

    int minCost(vector<int>& houses, int index, int before, int target){
        if(index==m){
            if(target==0)
                return 0;
            else
                return -1;
        }

        if(target==0){
            int c=0;
            vector<int> tempHouses=houses;
            for(int i=index;i<m;i++){
                if(tempHouses[i]==0){
                    if(i-1>=0){
                        tempHouses[i]=tempHouses[i-1];
                        c=c+cost[i][tempHouses[i]-1];
                    }
                }else{
                    if(i-1>=0 && tempHouses[i]==0){
                        tempHouses[i-1]=tempHouses[i];
                        c=c+cost[i][tempHouses[i]-1];
                    }
                    if(i-1>=0 && tempHouses[i]!=tempHouses[i-1]){
                        return -1;
                    }
                }
            }
            return c;
        }

        int mini=MAX;
        int v;
        if(houses[index]==0){
            for(int i=1;i<=n;i++){
                houses[index]=i;
                if(index>0){
                    if(houses[index]==houses[index-1]){
                        v=dp[index+1][i][target]==-1?minCost(houses, index+1, i, target):dp[index+1][i][target];
                    }else{
                        v=dp[index+1][i][target-1]==-1?minCost(houses, index+1, i, target-1):dp[index+1][i][target-1];
                    }
                }else{
                    v=dp[index+1][i][target-1]==-1?minCost(houses, index+1, i, target-1):dp[index+1][i][target-1];
                }
                if(v!=-1)
                    mini=min(mini,v+cost[index][i-1]);
            }
            houses[index]=0;
        }else{
            if(index>0){
                if(houses[index]==houses[index-1]){
                    v=dp[index+1][houses[index]][target]==-1?minCost(houses, index+1, houses[index], target):dp[index+1][houses[index]][target];
                }else{
                    v=dp[index+1][houses[index]][target-1]==-1?minCost(houses, index+1, houses[index], target-1):dp[index+1][houses[index]][target-1];
                }
            }else{
                v=dp[index+1][houses[index]][target-1]==-1?minCost(houses, index+1, houses[index], target-1):dp[index+1][houses[index]][target-1];
            }

            if(v!=-1)
                mini=min(mini,v);
        }

        dp[index][before][target]=mini;
        return mini==MAX?-1:mini;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& costMat, int hcnt, int colcnt, int target) {
        cost = costMat;
        m=hcnt;
        n=colcnt;
        clearDP();

        return minCost(houses,0,0,target);
    }
};

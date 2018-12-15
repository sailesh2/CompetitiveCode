class Solution {
private:
    int MIN_SUM=0;
    vector<int> dp;

    void clearDP(int n){
        dp.clear();
        for(int i=0;i<=n;i++){
            dp.push_back(MIN_SUM);
        }
    }

    void minSumTraverse(int row, vector<vector<int>>& triangle){
        if(row==triangle.size()){
            return;
        }
        minSumTraverse(row+1,triangle);
        for(int i=0;i<=row;i++){
            dp[i]=triangle[row][i]+min(dp[i],dp[i+1]);
        }
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        clearDP(triangle.size());
        minSumTraverse(0,triangle);
        return dp[0];
    }
};

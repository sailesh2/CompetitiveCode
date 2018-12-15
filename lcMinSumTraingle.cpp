class Solution {
private:
    int MIN_SUM=1000000000;
    vector<vector<int>> dp;

    void clearDP(int n){
        dp.clear();
        for(int i=0;i<=n;i++){
            vector<int> child;
            for(int j=0;j<=i;j++){
                child.push_back(MIN_SUM);
            }
            child.push_back(MIN_SUM);
            dp.push_back(child);
        }
    }

    int minSumTraverse(int row, int col, vector<vector<int>>& triangle){
        if(row==triangle.size()){
            return 0;
        }
        dp[row][col] = triangle[row][col]
                        + min(dp[row+1][col]!=MIN_SUM ? dp[row+1][col] : minSumTraverse(row+1,col,triangle)
                            , dp[row+1][col+1]!=MIN_SUM ? dp[row+1][col+1] : minSumTraverse(row+1,col+1,triangle));

        return dp[row][col];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        clearDP(triangle.size());
        return minSumTraverse(0,0,triangle);
    }
};

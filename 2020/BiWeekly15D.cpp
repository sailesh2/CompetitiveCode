class Solution {
private:
    int dp[205][205];
    int n,m;
    vector<vector<int>> mat;
    int MIN = -100000007;
    int MAX = 1000000007;

    void clearDP(){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++)
                dp[i][j]=MIN;
        }
    }

    int minSum(int row, int prevCol){
        if(row==n)
            return 0;

        int mini=MAX;

        for(int i=0;i<m;i++){
            if(i!=prevCol){
                int v = ((dp[row+1][i]==MIN)?minSum(row+1,i):dp[row+1][i]);
                mini=min(mini,v+mat[row][i]);
            }
        }

        if(mini==MAX)
            mini=0;
        if(prevCol!=-1)
        dp[row][prevCol]=mini;
        return mini;
    }

public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        mat = arr;
        n=arr.size();
        m=arr[0].size();
        clearDP();
        if(n==1)
            return mat[0][0];

        return minSum(0,-1);
    }
};

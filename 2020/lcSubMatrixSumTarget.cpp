class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n= matrix.size();
        int m = matrix[0].size();

        int dp[n][m];

        int ctr=0;
        set<int> st;

        for(int i=0;i<n;i++){
            int c=0;

            for(int j=0;j<m;j++){
                c=c+matrix[i][j];
                dp[i][j] = c + ((i-1>=0)?dp[i-1][j]:0);
                if(dp[i][j]==target)
                    ctr++;
                for(int k=0;k<j;k++){
                    if(dp[i][k]==dp[i][j]-target)
                        ctr++;
                }
                for(int k=0;k<i;k++){
                    if(dp[k][j]==dp[i][j]-target)
                        ctr++;
                }
            }
        }

        return ctr;
    }
};

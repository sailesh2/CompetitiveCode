class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();

        int maxSquare=min(n,m);

        int dp[n][m];
        int dp2[n][m];
        int ctr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=matrix[i][j];
                ctr=ctr+dp[i][j];
            }
        }
        for(int k=2;k<=maxSquare;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]==1 && i-1>=0 && dp[i-1][j]==1 && j-1>=0 && dp[i][j-1]==1 && dp[i-1][j-1]==1){
                        dp2[i][j]=1;
                        ctr++;
                    }else{
                        dp2[i][j]=0;
                    }
                }
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    dp[i][j]=dp2[i][j];
            }
        }

        return ctr;
    }
};

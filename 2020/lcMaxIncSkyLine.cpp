class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int gridNew[n][m];
        int maxi;
        for(int i=0;i<n;i++){
            maxi=0;
            for(int j=0;j<m;j++){
                maxi=max(maxi,grid[i][j]);
            }
            for(int j=0;j<m;j++){
                gridNew[i][j]=maxi;
            }
        }

        for(int i=0;i<m;i++){
            maxi=0;
            for(int j=0;j<n;j++){
                 maxi=max(maxi,grid[j][i]);
            }
            for(int j=0;j<n;j++){
                gridNew[j][i]=min(maxi,gridNew[j][i]);
            }
        }

        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum=sum+gridNew[i][j]-grid[i][j];
            }
        }

        return sum;
    }
};

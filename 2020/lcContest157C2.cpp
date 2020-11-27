class Solution {
private:
    int dp[500][500]={0};
    int n,m;

    void clearDP(){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++)
                dp[i][j]=-;1
        }
    }

    int crawl(int x, int y,vector<vector<int>>& grid){
        if(y-1>=0){
            if(dp[x][y-1]==-1)
                maxi=max(maxi,crawl(x,y-1,grid));
            else
                maxi=max(maxi,dp[x][y-1]);
        }
        if(y+1<m){
            if(dp[x][y+1]==-1)
                maxi=max(maxi,crawl(x,y+1,grid));
            else
                maxi=max(maxi,dp[x][y+1]);
        }
        if(x+1<n){
            if(dp[x+1][y]==-1)
                maxi=max(maxi,crawl(x+1,y,grid));
            else
                maxi=max(maxi,dp[x+1][y]);
        }
        dp[x][y]=maxi+grid[x][y];
        return dp[x][y];
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        clearDP();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    crawl(i,j,grid);
                }
            }
        }

        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                   maxi=max(maxi,grid[i][j]+(j-1>=0?dp[i][j-1]:0)+(j+1<m?dp[i][j+1]:0)+(i+1<n?dp[i+1][j]:0));
                }
            }
        }

        return maxi;
    }
};

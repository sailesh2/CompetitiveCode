class Solution {
private:
    int dp[105][105];
    int INF=1000000000;
    int n;

    void clearDP(){
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                dp[i][j]=-1;
            }
        }
    }

    int shortPath(int x, int y,vector<vector<int>>& grid){
        if(x==n-1 && y==n-1){
            return 0;
        }

        if(x>=n || y>=n)
            return INF;

        int a;
        if(dp[x+1][y]==-1)
            a=min(a,shortPath(x+1,y));
        else
            a=min(a,dp[x+1][y]);

        if(dp[x][y+1]==-1)
            a=min(a,shortPath(x,y+1));
        else
            a=min(a,dp[x][y+1]);

        if(dp[x+1][y+1]==-1)
            a=min(a,shortPath(x+1,y+1));
        else
            a=min(a,dp[x+1][y+1]);

        dp[x][y]=a;
        return a;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        clearDP();
        return shortPath(0,0,grid);
    }
};

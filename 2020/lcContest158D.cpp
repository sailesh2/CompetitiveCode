class Solution {
private:
    int dp[105][105][2];
    int MAX=1000000000;
    int n;
    void clearDP(){
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                dp[i][j][0]=-2;
                dp[i][j][1]=-2;
            }
        }
    }

    int minMoves(int x, int y, int o, vector<vector<int>>& grid, int prevX, int prevY, int prevO){
        //cout<<x<<" "<<y<<" "<<o<<"\n";
        /*if(o==0){

            if(x>=n)
                return -1;
            if(y>=n-1)
                return -1;
        }else{
            if(x>=n-1)
                return -1;
            if(y>=n)
                return -1;
        }*/

        if(o==0 && x==n-1 && y==n-2)
            return 0;

        int mini=MAX,v;
        if(o==0){
            if(y+2<n && grid[x][y+2]==0){
                if(dp[x][y+1][o]==-2)
                    v=minMoves(x,y+1,o,grid,x,y,o);
                else
                    v=dp[x][y+1][o];
                 if(v>=0)
                    mini=min(mini,1+v);

            }
            if(x+1<n && y+1<n && grid[x+1][y]==0 && grid[x+1][y+1]==0){
                if(dp[x+1][y][o]==-2)
                    v=minMoves(x+1,y,o,grid,x,y,o);
                else
                    v=dp[x+1][y][o];
                 if(v>=0)
                    mini=min(mini,1+v);
            }

            if(x+1<n && y+1<n && !(prevX==x && prevY==y && prevO==1) && grid[x+1][y]==0 && grid[x+1][y+1]==0){
                if(dp[x][y][1]==-2)
                    v=minMoves(x,y,1,grid,x,y,o);
                else
                    v=dp[x][y][1];

                if(v>=0)
                    mini=min(mini,1+v);
            }
        }else{

            if(x+1<n && y+1<n && grid[x][y+1]==0 && grid[x+1][y+1]==0){
                if(dp[x][y+1][o]==-2)
                    v=minMoves(x,y+1,o,grid,x,y,o);
                else
                    v=dp[x][y+1][o];
                 if(v>=0)
                    mini=min(mini,1+v);

            }
            if(x+2<n && grid[x+2][y]==0){
                if(dp[x+1][y][o]==-2)
                    v=minMoves(x+1,y,o,grid,x,y,o);
                else
                    v=dp[x+1][y][o];
                 if(v>=0)
                    mini=min(mini,1+v);

            }
            if(x+1<n && y+1<n && !(prevX==x && prevY==y && prevO==0) && grid[x][y+1]==0 && grid[x+1][y+1]==0){
                if(dp[x][y][0]==-2)
                    v=minMoves(x,y,0,grid,x,y,o);
                else
                    v=dp[x][y][0];
                 if(v>=0)
                    mini=min(mini,1+v);

            }
        }

        if(mini==MAX)
            mini=-1;
        dp[x][y][o]=mini;
        return mini;
    }
public:
    int minimumMoves(vector<vector<int>>& grid) {
        n=grid.size();
        clearDP();
        return minMoves(0,0,0,grid,-1,-1,-1);
    }
};

class Solution {
private:

    bool rotNeighbor(vector<vector<int>>& grid, int x, int y){
        int n=grid.size();
        int m=grid[0].size();

        bool canRot=false;
        if(x-1>=0 && grid[x-1][y]==1){
            grid[x-1][y]=2;
            canRot=true;
        }
        if(y-1>=0 && grid[x][y-1]==1){
            grid[x][y-1]=2;
            canRot=true;
        }
        if(x+1<n && grid[x+1][y]==1){
            grid[x+1][y]=2;
            canRot=true;
        }
        if(y+1<m && grid[x][y+1]==1){
            grid[x][y+1]=2;
            canRot=true;
        }

        return canRot;
    }

    bool rot(vector<vector<int>>& grid){
        bool canRot = false;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> tempGrid = grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    if(rotNeighbor(tempGrid, i , j)){
                        canRot=true;
                    }
                }
            }
        }
        grid = tempGrid;
        return canRot;
    }

    bool freshLeft(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return true;
                }
            }
        }
        return false;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int t=0;

        while(rot(grid)){
            t++;
        }

        return freshLeft(grid) ? -1 : t;
    }
};

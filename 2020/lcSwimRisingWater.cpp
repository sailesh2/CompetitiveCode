class Solution {
private:
    int has[60][60];
    int n;

    void clearDP(){
        for(int i=0;i<60;i++){
            for(int j=0;j<60;j++)
                has[i][j]=-1;
        }
    }

    bool isPossibleSwim(int t, int startX, int startY, vector<vector<int>>& tTimeGrid){
        return startX>=0 && startY>=0 && startX<n && startY<n &&
        has[startX][startY]==-1 && tTimeGrid[startX][startY]==t;
    }

    bool canReachEnd(int t, int startX, int startY, vector<vector<int>>& tTimeGrid){
        if(startX == n-1 && startY == n-1 && tTimeGrid[startX][startY]==t)
            return true;
        if(startX<0 || startY<0 || startX >=n || startY >= n)
            return false;

        has[startX][startY]=0;
        if(isPossibleSwim(t,startX-1,startY, tTimeGrid)){
            if(canReachEnd(t,startX-1, startY, tTimeGrid)){
                return true;
            }
        }
        if(isPossibleSwim(t,startX+1,startY, tTimeGrid)){
            if(canReachEnd(t,startX+1, startY, tTimeGrid)){
                return true;
            }
        }
        if(isPossibleSwim(t,startX,startY-1, tTimeGrid)){
            if(canReachEnd(t,startX, startY-1, tTimeGrid)){
                return true;
            }
        }
        if(isPossibleSwim(t,startX,startY+1, tTimeGrid)){
            if(canReachEnd(t,startX, startY+1, tTimeGrid)){
                return true;
            }
        }
        return false;
    }

    bool canSwim(int t, vector<vector<int>>& grid){
        vector<vector<int> > tTimeGrid;

        for(int i=0;i<grid.size();i++){
            vector<int> tTimeGridRow;
            for(int j=0;j<grid[i].size();j++){
                tTimeGridRow.push_back(max(t,grid[i][j]));
            }
            tTimeGrid.push_back(tTimeGridRow);
        }

        clearDP();
        if(isPossibleSwim(t,0,0,tTimeGrid))
            return canReachEnd(t,0,0,tTimeGrid);
        else
            return false;
    }

    int maxTime(vector<vector<int>>& grid){
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                maxi=max(maxi,grid[i][j]);
            }
        }

        return maxi;
    }

    int leastTimeToSwim(vector<vector<int>>& grid){

        int k = maxTime(grid);
        int ctr=1;
        int save=-1;
        int save2=-1;

        while(1){
            while(save+ctr<k && !canSwim(save+ctr, grid)){
                save2=save+ctr;
                ctr=ctr*2;
            }
            if(save==save2){
                break;
            }
            save=save2;
            ctr=1;
        }
        return save+1;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        if(n==0)
            return n;
        return leastTimeToSwim(grid);
    }
};

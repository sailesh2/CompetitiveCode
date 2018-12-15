class Solution {
private:
    set<pair<int,int> > dp;
    int n;
    void dfs(int i,int j,vector<vector<char> >& grid){
        int m=grid[i].size();
        if(i-1>=0 && grid[i-1][j]=='1' && dp.count(make_pair(i-1,j))==0){
            dp.insert(make_pair(i-1,j));
            dfs(i-1,j,grid);
        }
        if(j-1>=0 && grid[i][j-1]=='1' && dp.count(make_pair(i,j-1))==0){
            dp.insert(make_pair(i,j-1));
            dfs(i,j-1,grid);
        }
        if(j+1<m && grid[i][j+1]=='1' && dp.count(make_pair(i,j+1))==0){
            dp.insert(make_pair(i,j+1));
            dfs(i,j+1,grid);
        }
        if(i+1<n && grid[i+1][j]=='1' && dp.count(make_pair(i+1,j))==0){
            dp.insert(make_pair(i+1,j));
            dfs(i+1,j,grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        int ctr=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1' && dp.count(make_pair(i,j))==0){
                    ctr++;
                    dp.insert(make_pair(i,j));
                    dfs(i,j,grid);
                }
            }
        }
        return ctr;
    }
};

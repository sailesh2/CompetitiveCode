class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ctr=0;
        pair<int,int> nodes[500];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    ind[i][j]=ctr;
                    nodes[ctr]=make_pair(i,j);
                    ctr++;
                }
            }
        }

        int graph[ctr][ctr];
        for(int i=0;i<ctr;i++){
            pair<int,int> p=nodes[i];
            int x=p.first;
            int y=p.second;

            if(x-1>=0 && grid[x-1][y]>0){
                graph[i][ind[x-1][y]]=grid[x-1][y];
            }
            if(x+1<n && grid[x+1][y]>0){
                graph[i][ind[x+1][y]]=grid[x+1][y];
            }
            if(y-1>=0 && grid[x][y-1]>0){
                graph[i][ind[x][y-1]]=grid[x][y-1];
            }
            if(y+1<m && grid[x][y+1]>0){
                graph[i][ind[x][y+1]]=grid[x][y+1];
            }
        }

        for(int i=0;i<ctr;i++){
            for(int j=0;j<ctr;j++){
                if(i!=j){
                    for(int k=0;k<ctr;k++){
                        if(i!=k && j!=k){
                            dis=
                        }
                    }
                }
            }
        }

    }
};

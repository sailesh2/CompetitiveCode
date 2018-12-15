class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int ctr=0;

        int n=grid.size();
        if(n==0)
            return ctr;
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int k=j+1;k<m;k++){
                        if(grid[i][k]==1){
                            for(int l=i+1;l<n;l++){
                                if(grid[l][j]==1 && grid[l][k]==1){
                                    ctr++;
                                }
                            }
                        }
                    }
                }
            }
        }
        return ctr;
    }
};

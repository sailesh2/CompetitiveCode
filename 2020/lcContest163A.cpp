class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        k=(k%(n*m));
        vector<int> v;
        int c=0;
        int ctr=0,ctr2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back(grid[i][j]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ctr==k){
                    grid[i][j]=v[c++];
                }else{
                    ctr++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ctr2==ctr){
                    break;
                }else{
                    grid[i][j]=v[c++];
                    ctr2++;
                }
            }
        }

        return grid;
    }
};

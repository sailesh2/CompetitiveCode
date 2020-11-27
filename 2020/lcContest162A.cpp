class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int grid[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=0;
            }
        }
        for(int i=0;i<indices.size();i++){
            for(int j=0;j<m;j++){
                grid[indices[i][0]][j]++;
            }
            for(int j=0;j<n;j++){
                grid[j][indices[i][1]]++;
            }
        }

        int ctr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
      //           cout<<grid[i][j]<<" ";
                if(grid[i][j]%2!=0)
                    ctr++;
            }
            cout<<"\n";
        }

        return ctr;
    }
};

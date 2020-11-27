class Solution {
private:
    int rowSum[105][105];
    int colSum[105][105];
    void preprocess(vector<vector<int>> grid){
        for(int i=0;i<grid.size();i++){
            int sm=0;
            for(int j=0;j<grid[i].size();j++){
                sm=sm+grid[i][j];
                rowSum[i][j]=sm;
            }
        }

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<m;i++){
            int sm=0;
            for(int j=0;j<n;j++){
                sm=sm+grid[j][i];
                colSum[j][i]=sm;
            }
        }
    }

    int getRowSum(int startC, int endC, int row){
        if(startC-1>=0)
            return rowSum[row][endC] - rowSum[row][startC-1];
        else
            return rowSum[row][endC];
    }

    int getColSum(int startR, int endR, int col){
        if(startR-1>=0)
            return colSum[endR][col] - colSum[startR-1][col];
        else
            return colSum[endR][col];
    }
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {

        preprocess(grid);
        int maxi=0;

        for(int i=0;i<grid.size();i++){
            int c=0;
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    c++;
                }else{
                    c=0;
                }

                for(int l=c;l>=1;l--){

                    if(i-l+1>=0 && j-l+1>=0){

                        int r1=getRowSum(j-l+1,j,i-l+1);
                        int r2=getRowSum(j-l+1,j,i);
                        int c1=getColSum(i-l+1,i,j-l+1);
                        int c2=getColSum(i-l+1,i,j);

                        if(r1==l && r2==l && c1==l && c2==l)
                            maxi=max(maxi,l*l);
                    }
                }
            }
        }

        return maxi;
    }
};

class Solution {
private:
    int equalRows(vector<vector<int> > mat){
        int rows=0;
        for(int i=0;i<mat.size();i++){
            int z=0,o=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]!=0){
                    z=1;
                    break;
                }
            }

            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]!=1){
                    o=1;
                    break;
                }
            }
            if(z==0 || o==0)
                rows++;
        }
        return rows;
    }

    int maxFlipRow(vector<vector<int> > mat, int r, int v){
        int n=mat.size();
        for(int i=0;i<mat[r].size();i++){
            if(mat[r][i]==v){
                for(int j=0;j<n;j++){
                    mat[j][i]=1-mat[j][i];
                }
            }
        }
        int rows= equalRows(mat);
        //cout<<rows<<" "<<r<<" "<<v<<"\n";
        return rows;
    }
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int maxi=0;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,maxFlipRow(matrix,i,0));
            maxi=max(maxi,maxFlipRow(matrix,i,1));
        }
        return maxi;
    }
};

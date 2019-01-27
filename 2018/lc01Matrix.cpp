#define INF 100000000
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> updatedMatrix;
        int n=updateMatrix().size();
        int m=0;
        if(n>0){
            m= updatedMatrix[0].size();
        }

        for(int i=0;i<n;i++){
            vector<int> row;
            for(int j=0;j<m;j++){
                int val = INF;
                if(matrix[i][j]==0){
                    val=0;
                }else{
                    if(i-1>=0){
                        val=min(val,matrix[i-1][j]);
                    }
                    if(j-1>=0){
                        val=min(val,matrix[i][j-1]);
                    }
                    if(i+1<n){
                        if(matrix[i+1][j]==0){
                            val=0;
                        }
                    }
                    if(j+1<m){
                        if(matrix[i][j+1]==0){
                            val=0;
                        }
                    }
                }
                row.push_back(val);
            }
            updatedMatrix.push_back(row);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(updatedMatrix[i][j]==INF){
                    upda
                }
            }
        }
    }
};

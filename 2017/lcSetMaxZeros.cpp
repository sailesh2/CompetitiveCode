class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();

        if(n==0){
            return;
        }
        int m=matrix[0].size();
        int rows[100000]={0};
        int cols[100000]={0};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(rows[i]==1){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(cols[i]==1){
                    matrix[j][i]=0;
                }
            }
        }
    }
};

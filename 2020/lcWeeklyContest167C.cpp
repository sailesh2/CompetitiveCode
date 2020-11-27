class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m=mat[0].size();
        int colSum[n][m];
        int subSum[n][m];
        for(int i=0;i<m;i++){
            int s=0;
            for(int j=0;j<n;j++){
                s=s+mat[j][i];
                colSum[j][i]=s;
            }
        }

        for(int i=0;i<n;i++){
            int s=0;
            for(int j=0;j<m;j++){
                s=s+colSum[i][j];
                subSum[i][j]=s;
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=j;k>=0;k--){
                    if(k-1>=0 && (i-(j-k+1)>=0)){
                        int s=subSum[i][j]-subSum[i][k-1]-subSum[i-(j-k+1)][j]+subSum[i-(j-k+1)][k-1];
                        if(s<=threshold)
                            maxi=max(maxi,(j-k+1));
                    }else if(k-1==-1 && (i-(j-k+1)==-1)){
                        int s=subSum[i][j];
                        if(s<=threshold)
                            maxi=max(maxi,(j-k+1));
                    }
                }
            }
        }

        return maxi;

    }
};

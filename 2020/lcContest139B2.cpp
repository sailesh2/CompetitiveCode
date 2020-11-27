class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int maxi=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            int r=1;
            for(int j=0;j<n;j++){
                if(i!=j){
                    int cnt1=0,cnt2=0;
                    for(int k=0;k<m;k++){
                        if(matrix[i][k]!=matrix[j][k]){
                            cnt1=1;
                            break;
                        }
                    }

                    for(int k=0;k<m;k++){
                        if(matrix[i][k]!=1-matrix[j][k]){
                            cnt2=1;
                            break;
                        }
                    }
                    if(cnt1==0 || cnt2==0)
                        r++;
                }
            }
            maxi=max(maxi,r);
        }
        return maxi;
    }
};

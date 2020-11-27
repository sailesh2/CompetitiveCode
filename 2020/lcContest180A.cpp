class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {

        vector<int> ans;
        int n=maxtrix.size();
        int m=matrix[0].size();

        int rows[n];
        int col[m];

        for(int i=0;i<n;i++){
            int maxi=0;
            for(int j=0;j<m;j++){
                maxi=max(maxi,matrix[i][j]);
            }
            rows[i]=maxi;
        }

        for(int i=0;i<m;i++){
            int maxi=0;
            for(int j=0;j<n;j++){
                maxi=max(maxi,matrix[i][j]);
            }
            col[i]=maxi;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==row[i] && matrix[i][j]==col[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int cnt=0,cnt2=0;
        int ctr=0;
        int i,j;
        vector<int> ans;
        while(1){
            if(cnt==0){
                i=ctr;
                j=0;
            }else{
                j=ctr;
                i=0;
            }
            cnt2=0;
            while(i>=0 && j>=0){
                if(i<matrix.size() && j<matrix[i].size()){
                    cnt2=1;

                    ans.push_back(matrix[i][j]);
                }
                if(cnt==0){
                    i--;
                    j++;
                }else{
                    i++;
                    j--;
                }
            }
            if(cnt2==0)
                break;
            ctr++;
            cnt=1-cnt;
        }
        return ans;
    }
};

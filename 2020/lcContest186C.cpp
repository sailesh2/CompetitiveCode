class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> diags[200005];
        int maxL=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                diags[i+j].push_back(nums[i][j]);
                maxL=max(maxL,i+j);
            }
        }

        vector<int> ans;
        for(int i=0;i<=maxL;i++){
            for(int j=diags[i].size()-1;j>=0;j--){
                ans.push_back(diags[i][j]);
            }
        }
        return ans;
    }
};

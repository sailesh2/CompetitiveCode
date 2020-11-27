class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int s=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            s=s+nums[i];
            ans.push_back(s);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int ctr=0;
            for(int j=0;j<nums.size();j++){
                if(j!=i){
                    if(nums[j]<nums[i])
                        ctr++;
                }
            }
            ans.push_back(ctr);
        }
        return ans;
    }
};

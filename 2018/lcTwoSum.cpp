class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> has;
        vector<int> ans;
        map<int,int>::iterator hasIt;
        for(int i=0;i<nums.size();i++){
            hasIt=has.find(target-nums[i]);
            if(hasIt!=has.end()){
                ans.push_back(hasIt->second);
                ans.push_back(i);
                break;
            }else{
                has.insert(make_pair(nums[i],i));
            }
        }
        return ans;
    }
};

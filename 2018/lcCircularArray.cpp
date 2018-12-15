class Solution {
private:
    bool isLoop(vector<int>& nums){
        int len = nums.size();
        int slow=0,fast=0;
        for(int i=0;i<len;i++){
            if(abs(nums[slow])==len)
                return false;
            slow=(slow+nums[slow]+len)%len;
            fast=(fast+nums[fast]+len)%len;
            fast=(fast+nums[fast]+len)%len;
            if(abs(nums[slow])==len)
                return false;
            if(slow==fast)
                return true;
        }
        return false;
    }
public:
    bool circularArrayLoop(vector<int>& nums) {
        return isLoop(nums);
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int init=0,fast=0,slow=0,maxi=0;
        while(maxi<nums.size()){
            while(1){
                slow=nums[slow]-1;
                fast=nums[fast]-1;
                fast=nums[fast]-1;
                maxi=max(maxi,max(slow,fast));
                if(slow==fast)
                    break;
            }
            if(slow==fast){
                if(slow!=init){
                    slow=init;
                    while(slow!=fast){
                        slow=nums[slow]-1;
                        fast=nums[fast]-1;
                    }
                    return slow+1;
                } else{
                    init=maxi+1;
                    slow=init;
                    fast=init;
                }
            }
        }
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans=nums.size()+1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0){
                nums[i]=nums.size()+1;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i])-1<nums.size()){
                if(nums[abs(nums[i])-1]>0){
                    nums[abs(nums[i])-1]=-1*nums[abs(nums[i])-1];
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans=i+1;
                break;
            }
        }

        return ans;
    }
};

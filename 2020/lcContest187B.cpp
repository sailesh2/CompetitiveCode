class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int save=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(save!=-1){
                    if(i-save-1<k){
                        return false;
                    }
                }
                save=i;
            }
        }
        return true;
    }
};

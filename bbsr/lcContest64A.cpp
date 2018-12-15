class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int save,maxi=-10000000;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                save=i;
            }
        }
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(i!=save){
                if(nums[save]<2*nums[i]){
                    cnt=1;
                    break;
                }
            }
        }
        if(cnt==0){
            return save;
        }else{
            return -1;
        }
    }
};

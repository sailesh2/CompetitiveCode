class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mini,mini2,cnt=0;
        for(int i=0;i<nums.size();i++){
            if(i>1 && cnt==1 && nums[i]>mini2){
                cnt=2;
                break;
            }

            if(i>0 && nums[i]>mini){
                if(cnt==0)
                    mini2=nums[i];
                else
                    mini2=min(mini2,nums[i]);
                cnt=1;
            }
            if(i==0)
                mini=nums[i];
            else
                mini=min(mini,nums[i]);
        }
        return cnt==2;
    }
};

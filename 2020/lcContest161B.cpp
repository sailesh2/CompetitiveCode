class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(nums.size()<k)
            return 0;
        int ctr=0;
        int save0=0,save1=0,save2=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                ctr++;
            }
            if(ctr==k){
                save2=i;
                break;
            }
        }
        int sm=0,next=save2+1;
        ctr=0;
        for(int i=next;i<nums.size();i++){
            if(nums[i]%2!=0){
                ctr=0;
                while(save0<nums.size() && nums[save0]%2==0){
                    ctr++;
                    save0++;
                }
                ctr++;
                save0++;
                sm=sm+(ctr)*(i-save2);
                save2=i;
            }
        }
        //if(nums[nums.size()-1]%2==0){
                ctr=0;
                while(save0<nums.size() && nums[save0]%2==0){
                    ctr++;
                    save0++;
                }
                ctr++;
                save0++;
                sm=sm+(ctr)*(nums.size()-save2);
        //}

        return sm;
    }
};

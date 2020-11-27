class Solution {
private:
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int s=0;
        int maxi=0,mini=0;
        for(int i=0;i<nums.size()-1;i++){
            s=s+abs(nums[i+1]-nums[i]);
            if(i==0){
                maxi=min(nums[i],nums[i+1]);
                mini=max(nums[i],nums[i+1]);
            }else{
                maxi=max(maxi,min(nums[i],nums[i+1]));
                mini=min(mini,max(nums[i],nums[i+1]));
            }
        }
        int v = max(0,2*(maxi-mini));
        if(nums.size()>=3){
            for(int i=1;i<nums.size()-1;i++){
                if(abs(nums[i]-nums[i-1])<abs(nums[i-1]-nums[nums.size()-1])){
                    v=max(v,abs(nums[i-1]-nums[nums.size()-1]) - abs(nums[i]-nums[i-1]) );
                }
            }

            for(int i=nums.size()-2;i>=1;i--){
                if(abs(nums[i+1]-nums[i])<abs(nums[0]-nums[i+1])){
                    v=max(v,abs(nums[0]-nums[i+1]) - abs(nums[i+1]-nums[i]));
                }
            }
        }
        return s+v;
    }
};

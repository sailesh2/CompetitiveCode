class Solution {
private:
    bool isZeroPresent(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                return true;
        }

        return false;
    }

    int longSubArr(vector<int>& nums){
        int n=nums.size();
        int left[n],right[n];

        int ctr=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0)
                ctr=0;
            else
                ctr++;
            right[i]=ctr;
        }
        ctr=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                ctr=0;
            else
                ctr++;
            left[i]=ctr;
        }

        int maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(i==0){
                    if(i+1<n)
                    maxi=max(maxi,right[i+1]);
                }else if(i==n-1){
                    if(i-1>=0)
                    maxi=max(maxi,left[i-1]);
                }else{
                    maxi=max(maxi,left[i-1]+right[i+1]);
                }
            }
        }

        return maxi;
    }
public:
    int longestSubarray(vector<int>& nums) {
        if(!isZeroPresent(nums)){
            return nums.size()-1;
        }

        return longSubArr(nums);
    }
};

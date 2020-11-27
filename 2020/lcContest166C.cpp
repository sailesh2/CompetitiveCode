class Solution {
private:
    long long int thres;
    int MAX=1000005;

    bool isBiggerSum(int div, vector<int>& nums){
        long long int s=0;
        if(div==0)
            return true;
        for(int i=0;i<nums.size();i++){
            s=s+(int)ceil((double)nums[i]/div);
            if(s>thres)
                return true;
        }

        return s>thres;
    }

    int smallDiv(vector<int>& nums){
        int ctr=1;
        int save=-1;
        int save2=-1;

        while(1){
            while(save+ctr<=MAX && isBiggerSum(save+ctr,nums)){
                save2=save+ctr;
                ctr=ctr*2;
            }
            if(save==save2){
                break;
            }
            save=save2;
            ctr=1;
        }
        return save+1;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        thres=threshold;
        return smallDiv(nums);
    }
};

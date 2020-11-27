class Solution {
private:
    int zigzagEven(vector<int> nums){
        int ctr=0;

        for(int i=1;i<nums.size();i++){

            if(i%2==0){
                if(nums[i]<nums[i-1]){

                }else{
                    ctr=ctr+nums[i]-nums[i-1]+1;
                    nums[i]=nums[i-1]-1;
                }
            }else{
                if(nums[i]>nums[i-1]){

                }else{
                    ctr=ctr+nums[i-1]-nums[i]+1;
                    nums[i-1]=nums[i]-1;
                }
            }
        }
        return ctr;
    }

    int zigzagOdd(vector<int> nums){

        int ctr2=0;

        for(int i=1;i<nums.size();i++){

            if(i%2!=0){
                if(nums[i]<nums[i-1]){

                }else{
                    ctr2=ctr2+nums[i]-nums[i-1]+1;
                    nums[i]=nums[i-1]-1;
                }
            }else{
                if(nums[i]>nums[i-1]){

                }else{
                    ctr2=ctr2+nums[i-1]-nums[i]+1;
                    nums[i-1]=nums[i]-1;
                }
            }
        }
        return ctr2;
    }
    int zigzag(vector<int> nums){



        return min(zigzagEven(nums),zigzagOdd(nums));
    }
public:
    int movesToMakeZigzag(vector<int>& nums) {
        return zigzag(nums);
    }
};

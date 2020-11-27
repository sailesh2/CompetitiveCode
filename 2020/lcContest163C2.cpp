class Solution {
private:
    int dp[100005][3];
    int n;
    void clearDP(){
        for(int i=0;i<=n;i++){
        dp[i][0]=-1;
        dp[i][1]=-1;
        dp[i][2]=-1;
        }
    }

    void maxSum3(vector<int>& nums){

        for(int index=n-1;index>=0;index--){
            dp[index][nums[index]%3]=nums[index];
            if(nums[index]%3==0){
                if(dp[index+1][0]!=-1)
                dp[index][0]=max(dp[index][0],dp[index+1][0]+nums[index]);
                if(dp[index+1][1]!=-1)
                dp[index][1]=max(dp[index][1],dp[index+1][1]+nums[index]);
                if(dp[index+1][2]!=-1)
                dp[index][2]=max(dp[index][2],dp[index+1][2]+nums[index]);
            }else if(nums[index]%3==1){
                if(dp[index+1][2]!=-1)
                dp[index][0]=max(dp[index][0],dp[index+1][2]+nums[index]);
                if(dp[index+1][0]!=-1)
                dp[index][1]=max(dp[index][1],dp[index+1][0]+nums[index]);
                if(dp[index+1][1]!=-1)
                dp[index][2]=max(dp[index][2],dp[index+1][1]+nums[index]);
            }else{
                if(dp[index+1][1]!=-1)
                dp[index][0]=max(dp[index][0],dp[index+1][1]+nums[index]);
                if(dp[index+1][2]!=-1)
                dp[index][1]=max(dp[index][1],dp[index+1][2]+nums[index]);
                if(dp[index+1][0]!=-1)
                dp[index][2]=max(dp[index][2],dp[index+1][0]+nums[index]);
            }

            dp[index][0]=max(dp[index][0],dp[index+1][0]);
            dp[index][1]=max(dp[index][1],dp[index+1][1]);
            dp[index][2]=max(dp[index][2],dp[index+1][2]);

            //cout<<dp[index][0]<<" "<<dp[index][1]<<" "<<dp[index][2]<<"\n";
        }
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        n=nums.size();
        clearDP();
        maxSum3(nums);
        return max(0,dp[0][0]);
    }
};

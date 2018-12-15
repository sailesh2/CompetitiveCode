class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> subsets;

        if(nums.size()==0){

            return subsets;
        }
        sort(nums.begin(),nums.end());

        int dp[nums.size()];
        int has[nums.size()];
        int ansPos=-1;
        int ans=-1;
        for(int i=nums.size()-1;i>=0;i--){
            int save=-1;
            int maxi=-1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]%nums[i] == 0){
                    if(dp[j]>maxi){
                        maxi=dp[j];
                        save=j;
                    }
                }
            }
            dp[i]=maxi+1;
            has[i]=save;
            if(dp[i]>ans){
                ans=dp[i];
                ansPos=i;
            }
        }
        while(ansPos!=-1){
            subsets.push_back(nums[ansPos]);
            ansPos=has[ansPos];
        }
        return subsets;
    }
};

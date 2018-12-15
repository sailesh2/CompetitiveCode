#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int dp[10005]={0};
    int cnt[10005]={0};

    int deleteAndEarnDP(vector<int>& nums, int ind,int *has){
        int n=nums.size();
        if(ind>=n)
            return 0;
        int v=0;
        for(int i=ind;i<n;i++){
            if(has[nums[i]]==0){
                has[nums[i]]=1;
                has[nums[i]+1]=1;
                has[nums[i]-1]=1;
                if(dp[i+1]==0)
                    v=max(v,deleteAndEarnDP(nums,i+1,has)+nums[i]*cnt[nums[i]]);
                else
                    v=max(v,dp[i+1]+nums[i]*cnt[nums[i]]);
                has[nums[i]]=0;
                has[nums[i]+1]=0;
                has[nums[i]-1]=0;
            }
        }
        dp[ind]=v;
        return v;
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            cnt[nums[i]]++;
        }
        int has[10005]={0};
        return deleteAndEarnDP(nums,0,has);
    }
};

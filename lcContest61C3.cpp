#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int dp[100005]={0};
    int cnt[100005]={0};
    int n;

    int deleteAndEarnDP(int * dis, int ind){
        if(ind>=n)
            return 0;
        int v=0;
        for(int i=ind;i<n;i++){
            if(dis[i+1]>dis[i]+1){
                if(dp[i+1]==0)
                    v=max(v,deleteAndEarnDP(dis,i+1)+dis[i]*cnt[dis[i]]);
                else
                    v=max(v,dp[i+1]+dis[i]*cnt[dis[i]]);
            }else{
                if(dp[i+2]==0)
                    v=max(v,deleteAndEarnDP(dis,i+2)+dis[i]*cnt[dis[i]]);
                else
                    v=max(v,dp[i+2]+dis[i]*cnt[dis[i]]);
            }
        }
        dp[ind]=v;
        return v;
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int distinct[100005];
        int ctr=0;
        for(int i=0;i<nums.size();i++){
            if(cnt[nums[i]]==0)
                distinct[ctr++]=nums[i];
            cnt[nums[i]]++;
        }
        sort(distinct,distinct+ctr);
        n=ctr;
        return deleteAndEarnDP(distinct,0);
    }
};

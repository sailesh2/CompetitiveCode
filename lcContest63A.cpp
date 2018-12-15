#include<bits/stdc++.h>

using namespace std;


class Solution {
private:
    vector<int> c;
    int dp[2000];
    void clearDP(){
        for(int i=0;i<2000;i++)
            dp[i]=-1;
    }
    int findMinDP(int ind){
        int a,b,mini;
        if(ind>=c.size())
            return 0;
        if(dp[ind+1]==-1){
            a=findMinDP(ind+1);
        }else{
            a=dp[ind+1];
        }

        if(dp[ind+2]==-1){
            b=findMinDP(ind+2);
        }else{
            b=dp[ind+2];
        }
        mini=c[ind]+min(a,b);
        dp[ind]=mini;
        return mini;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        c=cost;
        clearDP();
        int sm=min(findMinDP(0),findMinDP(1));
        return sm;
    }
};

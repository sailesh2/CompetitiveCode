
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int cnt=0;
        long long int mini,s;
        for(int i=0;i<nums.size();i++){
            s=0;
            for(int j=0;j<nums.size();j++){
                s=s+abs(nums[i]-nums[j]);
            }
            if(cnt==0)
                mini=s;
            else
                mini=min(mini,s);
            cnt=1;
        }
        return mini;
    }
};

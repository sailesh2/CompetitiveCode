#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> pairs;
        int ctr=1,j,cnt=0,ans;
        sort(nums.begin(),nums.end());
        while(cnt<=k){
            pairs.clear();
            for(int i=0;i<nums.size();i++){
                j=i+ctr;
                if(j<nums.size())
                    pairs.push_back(abs(nums[i]-nums[j]));
            }
            sort(pairs.begin(),pairs.end());
            ctr++;
            if(cnt+pairs.size()>=k){
                ans=pairs[k-cnt-1];
                break;
            }
            cnt=cnt+pairs.size();
        }
        return ans;

    }
};

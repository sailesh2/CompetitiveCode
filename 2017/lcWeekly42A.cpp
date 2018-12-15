#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> has;
        int dup,mis;
        for(int i=0;i<nums.size();i++){
            if(has.count(nums[i])==1){
                dup=nums[i];
            }
            has.insert(nums[i]);
        }
        for(int i=1;i<=nums.size();i++){
            if(has.count(i)==0){
                mis=i;
                break;
            }
        }
        vector<int> ans;
        ans.push_back(dup);
        ans.push_back(mis);
        return ans;


    }
};

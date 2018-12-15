#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int ind;
        for(int i=0;i<nums.size();i++){
            ind=nums[i]-1;
            nums[ind]=-1*nums[ind];
        }
        vector<int> duplicates;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                duplicates.push_back(i+1);
            }
        }
        return duplicates;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    Solution solution;
    solution.findDuplicates(nums);
    return 0;
}

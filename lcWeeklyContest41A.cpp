#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int ctr=0;
        vector<int> nums1=nums;
        vector<int> nums2=nums;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                if(ctr==0){
                    nums1[i]=nums[i+1];
                    nums2[i+1]=nums[i];
                }
                ctr++;
            }
        }
        ctr=0;
        for(int i=0;i<nums1.size()-1;i++){
            if(nums1[i]>nums1[i+1]){
                ctr++;
            }
        }

        int ctr2=0;
        for(int i=0;i<nums2.size()-1;i++){
            if(nums2[i]>nums2[i+1]){
                ctr2++;
            }
        }
        return ctr==0 || ctr2==0;
    }
};
int main(){
    return 0;
}

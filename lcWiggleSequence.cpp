#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
        int ctr=1,cnt=-1,save=nums[0];
        for(int i=1;i<nums.size();i++){
            if(cnt==-1){
                if(nums[i]>save){
                    save=nums[i];
                    cnt=0;
                    ctr++;
                }else if(nums[i]<save){
                    save=nums[i];
                    cnt=1;
                    ctr++;
                }
            }else if(cnt==0){
                if(nums[i]<save){
                    save=nums[i];
                    cnt=1;
                    ctr++;
                }else{
                    save=max(save,nums[i]);
                }
            }else{
                if(nums[i]>save){
                    save=nums[i];
                    cnt=0;
                    ctr++;
                }else{
                    save=min(save,nums[i]);
                }
            }
        }
        return ctr;
    }
};

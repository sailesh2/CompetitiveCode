#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int sum=0,sum2=0,temp;
        int cnt=0,cnt2=0,tempCnt2;
        if(nums.size()==0)
            return 0;
        if(nums[0]>0){
            sum2=nums[0];
            cnt2=1;
        }
        for(int i=1;i<nums.size();i++){
            if(i==nums.size()-1){
                if(cnt==0){
                    sum2=max(nums[i]+sum,sum2);
                }
            }else{
                if(nums[i]+sum>sum2){
                    temp=sum;
                    sum=sum2;
                    sum2=nums[i]+temp;
                    tempCnt2=cnt2;
                    cnt2=cnt;
                    cnt=tempCnt2;
                }else if(nums[i]+sum<sum2){
                    sum=sum2;
                    cnt=cnt2;
                } else{
                    tempCnt2=cnt2;
                    if(cnt==0 || cnt2==0)
                        cnt2=0;
                    cnt=tempCnt2;
                    sum=sum2;
                }
            }
        }
        return sum2;
    }
};

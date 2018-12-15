#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int has[100005]={0};
        int ans=0,sum=0;
        for(int i=0;i<nums.size();i++){
            has[nums[i]]++;
            sum=sum+nums[i];

        }
        int save,a,b,maxi;
        while(1){
            save=-1;
            maxi=-1;
            int h[100005]={0};
            for(int i=0;i<nums.size();i++){
                if(has[nums[i]]!=0 && h[nums[i]]==0){
                    a=0;
                    if(has[nums[i]+1]!=0)
                        a=a+(nums[i]+1)*has[nums[i]+1];
                    b=0;
                    if(has[nums[i]-1]!=0)
                        b=b+(nums[i]-1)*has[nums[i]-1];

                    if(sum-(a+b)>maxi){
                        maxi=sum-(a+b);
                        save=nums[i];
                    }
                    h[nums[i]]=0;
                }
            }
            if(save==-1)
                break;
            ans=ans+save*has[save];
            sum=sum-(save*has[save]);
            sum=sum-((save+1)*has[save+1]);
            sum=sum-((save-1)*has[save-1]);
            has[save+1]=0;
            has[save-1]=0;
        }
    }
};

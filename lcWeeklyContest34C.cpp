#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int has[200005]={0};
        int ctr,maxi=0,k;
        for(int i=0;i<nums.size();i++){
            k=nums[i];
            ctr=0;
            while(1){
                if(has[k]==1)
                    break;
                has[k]=1;
                k=nums[k];
                ctr++;
            }
            maxi=max(maxi,ctr);
        }
        return ctr;
    }
};

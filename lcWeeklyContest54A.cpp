#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maxi=0,mini=100000000,first,c;
        map<int,pair<int,int> > pos;
        map<int,int> ctr;
        map<int,int>::iterator ctrIt;
        map<int,pair<int,int> >::iterator posIt;
        for(int i=0;i<nums.size();i++){
            ctrIt=ctr.find(nums[i]);
            if(ctrIt==ctr.end()){
                c=1;
            }else{
                c=ctrIt->second+1;
                ctr.erase(ctrIt);
            }
            ctr.insert(make_pair(nums[i],c));
            maxi=max(maxi,c);
            posIt=pos.find(nums[i]);
            if(posIt==pos.end()){
                pos.insert(make_pair(nums[i],make_pair(i,i)));
            }else{
                pair<int,int> p=posIt->second;
                first=p.first;
                pos.erase(posIt);
                pos.insert(make_pair(nums[i],make_pair(first,i)));
            }
        }
        for(int i=0;i<nums.size();i++){
            ctrIt=ctr.find(nums[i]);
            if(ctrIt!=ctr.end() && ctrIt->second==maxi){
                posIt=pos.find(nums[i]);
                mini=min(mini,posIt->second.second-posIt->second.first+1);
            }
        }
        return mini;
    }
};

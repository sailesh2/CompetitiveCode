#include<bits/stdc++.h>

using namespace std;


class Solution {
private:
    int shouldContinue(int ind,vector<int> arr){
        int p=-1,a=-1;
        if(ind-1>=0){
            if(arr[ind-1]==arr[ind])
                p=1;
        }
        if(ind+1<arr.size()){
            if(arr[ind+1]==arr[ind])
                a=1;
        }
        if(p==1 && a==-1){
            return (ind+1)%2;
        } else if(p==-1 && a==1){
            return 1-((ind+1)%2);
        } else{
            return 2;
        }
    }
    int binSear(vector<int> arr){
        int ctr=1;
        int save=-1;
        int save2=-1;

        while(1){
            while(save+ctr<arr.size() && shouldContinue(save+ctr,arr)==0){
                save2=save+ctr;
                ctr=ctr*2;
            }
            if(shouldContinue(save+ctr,arr)==2)
                return arr[save+ctr];
            if(save==save2){
                break;
            }
            save=save2;
            ctr=1;
        }
        if(save==-1)
            return -1;
        return arr[save];
    }

public:
    int singleNonDuplicate(vector<int>& nums) {
        return binSear(nums);
    }
};



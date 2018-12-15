#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int diff[1000001]={0};

    int binSear(int cost){
        int ctr=1;
        int save=-1;
        int save2=-1;


        while(1){
            while(save+ctr<1000001 && diff[save+ctr]<cost){
                save2=save+ctr;
                ctr=ctr*2;
            }
            if(save==save2){
                break;
            }
            save=save2;
            ctr=1;
        }
        return save+1;
    }


public:
    int smallestDistancePair(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                diff[abs(nums[i]-nums[j])]++;
            }
        }
        for(int i=1;i<1000001;i++){
            diff[i]=diff[i]+diff[i-1];
        }
        return binSear(k);
    }
};

int main(){
return 0;
}

#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int p=1,j=0,ctr=0;
        for(int i=0;i<nums.size();i++){
            p=p*nums[i];
            if(p>=k){
                while(j<=i){
                    p=p/nums[j];
                    j++;
                }
            }else{
                ctr++;
            }
        }
        return ctr;
    }
};
int main(){
    return 0;
}

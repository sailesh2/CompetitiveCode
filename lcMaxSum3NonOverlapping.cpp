#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int hasMax[30000]={0};
    int hasMax2[30000]={0};
    int saveMax[30000]={0};
    int saveMax2[30000]={0};
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        long long int sm=0,maxi=-1,maxiSum2=-1,save=-1,save2=-1;
        for(int i=nums.size()-1;i>=0;i--){
            sm=sm+nums[i];

            if(i+k<nums.size()){
                sm=sm-nums[i+k];
                if(sm>maxi){
                    maxi=sm;
                    save=i;
                }
                hasMax[i]=maxi;
                saveMax[i]=save;
                if(hasMax[i+k]!=-1){
                    if(sm+hasMax[i+k]>maxiSum2){
                        maxiSum2=sm+hasMax[i+k];
                        save2=i;
                    }
                } else{
                    maxiSum2=-1;
                }

                hasMax2[i]=maxiSum2;
                saveMax2[i]=save2;
            } else if(i+k==nums.size()){
                if(sm>maxi){
                    maxi=sm;
                    save=i;
                }
                hasMax[i]=maxi;
                saveMax[i]=save;
                hasMax2[i]=-1;
                saveMax2[i]=save2;
            } else{
                hasMax[i]=-1;
                hasMax2[i]=-1;
            }
        }

        sm=0;
        long long int maxiAns2=-1;
        int ans1=-1,ans2=-1,ans3=-1;
        for(int i=0;i<nums.size();i++){
            sm=sm+nums[i];
            if(i-k>=0){
                sm=sm-nums[i-k];
                if(i+k<nums.size() && hasMax2[i+k]!=-1){
                    if(sm+hasMax2[i+k]>maxiAns2){
                        ans1=i;
                        ans2=saveMax2[i+k];
                        ans3=saveMax[ans2+k];
                        maxiAns2=sm+hasMax2[i+k];
                    }
                }
            } else if(i-k==-1){
                if(i+k<nums.size() && hasMax2[i+k]!=-1){
                    if(sm+hasMax2[i+k]>maxiAns2){
                        ans1=i;
                        ans2=saveMax2[i+k];
                        ans3=saveMax[ans2+k];
                        maxiAns2=sm+hasMax2[i+k];
                    }
                }
            }
        }
        vector<int> ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        ans.push_back(ans3);
        return ans;
    }
};


int main(){
    Solution solution;
    return 0;
}

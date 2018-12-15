#include<bits/stdc++.h>

using namespace std;


class Solution {
private:

    int sumArr[160001];
    void clearPrev(pair<int,int> *prev,int l){

        cout<<l<<"\n";
        pair<int,int> p=prev[l];
        int l1=p.first;
        int l2=p.second;
        sumArr[l]--;
        if(sumArr[l]<0)
            sumArr[l]=0;
        if(l1==0 || l2==0){
            sumArr[l1]--;

            if(sumArr[l1]<0)
                sumArr[l1]=0;
            sumArr[l2]--;

            if(sumArr[l2]<0)
                sumArr[l2]=0;
            return;
        }
        clearPrev(prev,l1);
        clearPrev(prev,l2);
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sm=0,ctr=0,ans,l;
        for(int i=0;i<nums.size();i++){
            sm=sm+nums[i];
        }
        if(sm%k!=0)
            return (1==2);

        ans=sm/k;
        pair<int,int> prev[sm+1];
        sumArr[0]=1;
        for(int i=1;i<=sm;i++){
            sumArr[i]=0;
            prev[i]=make_pair(0,0);
        }
        for(int i=0;i<nums.size();i++){
            for(int j=sm;j>=0;j--){
                if(sumArr[j]>0 && nums[i]+j<=sm){
                    sumArr[nums[i]+j]++;
                    prev[nums[i]+j]=make_pair(nums[i],j);

                    if(nums[i]+j==ans){
                        l=nums[i]+j;

                        cout<<ctr<<" "<<nums[i]<<" "<<j<<" "<<"\n";

                        clearPrev(prev,l);
                        ctr++;

                    cout<<sumArr[2]<<"\n";

                    sumArr[0]=1;
                    }
                }
            }
        }
        cout<<ctr;
        return (ctr==k);
    }
};

int main(){
    vector<int> a;
    a.push_back(4);
    a.push_back(3);
    a.push_back(2);
    a.push_back(3);
    a.push_back(5);
    a.push_back(2);
    a.push_back(1);

    Solution sol;
    sol.canPartitionKSubsets(a,4);
}

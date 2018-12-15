#include<bits/stdc++.h>

using namespace std;

class Solution {
vector<int> v;
vector<int> currPartSum;
int n;
int parts;
int partSum;
int isPossible;
int partsTakenCtr=0;
private:
    void canPartBT(int ind,vector<vector<int> >& p){
        if(ind==n){
            if(partsTakenCtr==parts){
                isPossible=1;
            }
            return;
        }
        if(v[ind]==0){
            canPartBT(ind+1,p);
        }
        int sp;
        set<int> partSumIncluded;
        for(int i=0;i<parts;i++){
            if(isPossible==1)
                return;

            sp=currPartSum[i];
            if(partSumIncluded.count(sp)==0){
                if(sp+v[ind]<=partSum){
                    if(sp+v[ind]==partSum){
                        partsTakenCtr++;
                    }
                    if(partsTakenCtr==parts-1){
                        isPossible=1;
                        return;
                    }
                    currPartSum[i]=currPartSum[i]+v[ind];
                    p[i].push_back(v[ind]);
                    canPartBT(ind+1,p);
                    p[i].pop_back();
                    currPartSum[i]=currPartSum[i]-v[ind];

                    if(sp+v[ind]==partSum){
                        partsTakenCtr--;
                    }
                }
                partSumIncluded.insert(sp);
            }

        }

    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sm=0;
        for(int i=0;i<nums.size();i++){
            sm=sm+nums[i];
        }
        if(sm%k!=0)
            return (1==2);
        partSum=sm/k;
        parts=k;
        v=nums;
        n=v.size();
        isPossible=0;
        vector<vector<int> > p;
        for(int i=0;i<k;i++){
            vector<int> p1;
            p.push_back(p1);
            currPartSum.push_back(0);
        }
        canPartBT(0,p);
        return isPossible==1;
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

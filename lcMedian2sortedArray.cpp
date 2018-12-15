#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    double findMedian(int num1L,int num1R,vector<int>& nums1,int num2L,int num2R,vector<int>& nums2,int done){
        if(num1R-num1L+num2R-num2L<=4){
            vector<int> middles;
            for(int i=num1L;i<=num1R;i++){
                cout<<nums1[i]<<" ";
                middles.push_back(nums1[i]);
            }
            cout<<"\n";
            for(int i=num2L;i<=num2R;i++){
                cout<<nums2[i]<<" ";
                middles.push_back(nums2[i]);
            }
            sort(middles.begin(),middles.end());
            int l,m1,m2;
            l=(nums1.size()+nums2.size());
            if(l%2==0){
                m1=l/2-1;
                m2=m1+1;
                //cout<<middles[m1-done]<<" "<<middles[m2-done];
                return ((double)middles[m1-done]+middles[m2-done])/2;
            }else{
                m1=l/2;
                return middles[m1-done];
            }
        }
        if(nums1[(num1L+num1R)/2]<nums2[(num2L+num2R)/2]){
            return findMedian(ceil(((float)num1L+num1R)/2),num1R,nums1,num2L,(num2L+num2R)/2,nums2,done+ceil(((float)num1L+num1R)/2)-num1L);
        }else{
            return findMedian(num1L,(num1L+num1R)/2,nums1,ceil(((float)num2L+num2R)/2),num2R,nums2,done+ceil(((float)num2L+num2R)/2)-num2L);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return findMedian(0,nums1.size()-1,nums1,0,nums2.size()-1,nums2,0);
    }
};

int main(){
    Solution sol;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(6);
    vector<int> v2;
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(7);
    v2.push_back(8);
    sol.findMedianSortedArrays(v1,v2);
}

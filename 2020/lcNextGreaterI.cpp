class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            int cnt=0,save;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    save=j;
                    break;
                }
            }

            for(;save<nums2.size();save++){
                if(nums2[save]>nums1[i]){
                    cnt=1;
                    ans.push_back(nums2[save]);
                    break;
                }
            }
            if(cnt==0){
                ans.push_back(-1);
            }
        }

        return ans;
    }
};

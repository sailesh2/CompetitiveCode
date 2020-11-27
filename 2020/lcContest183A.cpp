class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;

        sort(nums.begin(),nums.end());

        int s=0;
        for(int i=0;i<nums.size();i++){
            s=s+nums[i];
            pre[i]=s;
        }

        s=0;
        int save=0;
        for(int i=nums.size()-1;i>=0;i--){
            s=s+nums[i];
            if(i==0)
            {
                save=i;
                break;
            }
            if(s>pre[i-1]){
                save=i;
                break;
            }
        }

        for(int i=nums.size()-1;i>=save;i--)
            ans.push_back(nums[i]);

        return ans;
    }
};

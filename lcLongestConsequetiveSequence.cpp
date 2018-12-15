class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> isPresent;
        map<int,int> leftRange;
        map<int,int>::iterator leftRangeIt;
        map<int,int>::iterator rightRangeIt;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            l=0;
            r=0;
            if(isPresent.count(nums[i]-1)>0){
                leftRangeIt=leftRange.find(nums[i]-1);
                l=leftRangeIt->second+1;
            }
            if(isPresent.count(nums[i]+1)>0){
                rightRangeIt=rightRange.find(nums[i]+1);
                r=rightRangeIt->second+1;
            }
            maxi=max(maxi,l+r+1);
            isPresent.insert(nums[i]);
            leftRange.insert(make_pair(nums[i],l));
            rightRange.insert(make_pair(nums[i],r));
        }
        return maxi;
    }
};

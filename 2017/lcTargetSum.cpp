class Solution {
private:
    int ctr=0;
    int target;
    vector<int> orig;
    void backTrack(int sum, int ind){
        if(ind==orig.size()){
            if(sum==target){
                ctr++;
            }
            return;
        }
        backTrack(sum+orig[ind],ind+1);
        backTrack(sum-orig[ind],ind+1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        target = S;
        orig=nums;
        backTrack(0,0);
        return ctr;
    }
};

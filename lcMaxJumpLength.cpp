class Solution {
private:
    int notPossible[100000]={0};
    bool canJumpDP(int start,vector<int>& nums){
        if(start>=nums.size()){
            return false;
        }
        if(start==nums.size()-1){
            return true;
        }
        bool b=false;
        for(int i=1;i<=nums[start];i++){
            if(notPossible[start+i]==0)
                b=canJumpDP(start+i,nums);
            if(b)
                return b;
        }
        notPossible[start]=1;
        return b;
    }
public:
    bool canJump(vector<int>& nums) {
        return canJumpDP(0,nums);
    }
};

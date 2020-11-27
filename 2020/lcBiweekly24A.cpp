class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int maxi=10001;
        int save=0;
        for(int i=1;i<=maxi;i++){
            int cnt=0;
            int s=i;
            for(int j=0;j<nums.size();j++){
                s=s+nums[j];
                if(s<1){
                    cnt=1;
                    break;
                }
            }
            if(cnt==0){
                save=i;
                break;
            }
        }
        return save;
    }
};

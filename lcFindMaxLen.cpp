class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mp;
        map<int,int>::iterator mpIt;

        int maxi=0;
        if(nums.size()==0)
            return maxi;
        mp.insert(make_pair(0,-1));
        int cuml[nums.size()];
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                nums[i]=1;
            else
                nums[i]=-1;
            if(i==0){
                cuml[i]=nums[i];
            }else{
                cuml[i]=nums[i]+cuml[i-1];
            }
            mpIt=mp.find(cuml[i]);
            if(mpIt!=mp.end()){
                maxi=max(maxi,i-mpIt->second);
            }else{
                mp.insert(make_pair(cuml[i],i));
            }
        }
        return maxi;
    }
};

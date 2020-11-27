class Solution{
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int index=0;
        int lastIndex=0;
        int jumps=0;
        int save;
        while(1){
            int cnt=0;
            int maxi=0;
            if(lastIndex+1>min(index+nums[index],n-1))
                break;
            for(int i=lastIndex+1;i<=index+nums[index];i++){
                if(i>=n-1){
                   cnt=1;
                   break;
                }
                if(i+nums[i]>maxi){
                    maxi=i+nums[i];
                    save=i;
                }

            }
            lastIndex=index+nums[index];
            index=save;
            jumps++;

            if(cnt==1)
                break;
        }
        return jumps;
    }
};

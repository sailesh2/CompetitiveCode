class Solution {
private:
    long long int pow2[100005];

    long long int mod=1000000007;
    void setup(long long int n){
        pow2[0]=1;
        for(long long int i=1;i<=n;i++){
            pow2[i]=(pow2[i-1]*2)%mod;
        }
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long int ans=0;
        long long int n = nums.size();
        setup(n);
        for(int k=0;k<n;k++){

            if(2*nums[k]<=target)
                ans=(ans+1)%mod;
        }
        long long int i=0,j=n-1;


        while(i<=j){

            while(i<j && nums[i]+nums[j]>target)
                j--;
            if(i==j){
                break;
            }else{
                if(j-i-1>0)
                    ans=((ans+pow2[j-i])%mod-1+mod)%mod;
                else
                    ans=(ans+1)%mod;
            }
            i++;
        }
        return ans;
    }
};

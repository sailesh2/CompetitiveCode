class Solution {
private:
    vector<int> arr;
    int limit;
    int dp[100005];
    int n;

    void clearDP(){
        for(int i=0;i<=n+1;i++)
            dp[i]=-1;
    }

    int consSum(int index){
        int maxi=0;
        for(int i=index;i<index+k && i<n;i++){
            maxi=max(maxi,dp[i+1]==-1?consSum(i+1):dp[i+1] + arr[i]);
        }
        dp[index]=maxi;
        return maxi;
    }

public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        arr = nums;
        limit = k;
        n=nums.size();
        clearDP();

        for(int i=0;i<nums.size();i++){
            if(dp[i]==-1)
            maxi=max(maxi,consSum(i));
            else
            maxi=max(maxi,dp[i]);
        }

        return maxi;
    }
};

class Solution {
private:
    int n;

    bool allNeg(vector<int>& arr){
        for(int i=0;i<n;i++){
            if(arr[i]>=0)
                return false;
        }
        return true;
    }

    int minNeg(vector<int>& arr){
        int maxi=arr[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
public:
    int maximumSum(vector<int>& arr) {
        n=arr.size();

        if(allNeg(arr))
            return minNeg(arr);

        int dp[n][2];
        int maxi=0;
        for(int i=0;i<n;i++){
            if(i==0)
            {
                dp[i][0]=max(arr[i],0);
                dp[i][1]=max(arr[i],0);
            }else{
                if(arr[i]>=0){
                    dp[i][0] = dp[i-1][0]+arr[i];
                    dp[i][1] = dp[i-1][1]+arr[i];
                }else{
                    dp[i][0] = max(dp[i-1][0]+arr[i],0);
                    dp[i][1] = max(dp[i-1][0], max(dp[i-1][1]+arr[i],0));
                }
            }
            maxi=max(maxi,dp[i][0]);
            maxi=max(maxi,dp[i][1]);
        }

        return maxi;
    }
};

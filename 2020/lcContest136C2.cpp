class Solution {
private:
    int dp[505];

    void clearDP(){
        for(int i=0;i<505;i++)
            dp[i]=-1;
    }

    int maxSumPartDP(int index, vector<int> arr, int k){
        int glMax=0;
        int maxi=0;
        int ctr=0;
        for(int i=index;i<arr.size();i++){
            ctr++;
            if(ctr>k)
                break;
            maxi=max(maxi,arr[i]);
            if(dp[i+1]==-1)
                glMax=max(glMax,maxi*ctr + maxSumPartDP(i+1,arr,k));
            else
                glMax=max(glMax,maxi*ctr + dp[i+1]);
        }
        dp[index]=glMax;
        return glMax;
    }

public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        clearDP();
        return maxSumPartDP(0,A,K);
    }
};

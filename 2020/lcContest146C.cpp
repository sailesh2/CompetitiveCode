class Solution {
private:
    int DEFAULT=1000000007;
    int n;
    int dp[50][50];
    int preMax[50][50];
    void clearDP(){
        for(int i=0;i<50;i++){
            for(int j=0;j<50;j++)
                dp[i][j]=-1;
        }
    }

    void preMaxCompute(vector<int> arr){
        for(int i=0;i<n;i++){
            int maxi=0;
            for(int j=i;j<n;j++){
                maxi=max(maxi,arr[j]);
                preMax[i][j]=maxi;
            }
        }
    }

    void setup(vector<int> arr){
        n=arr.size();
        clearDP();
        preMaxCompute(arr);
    }

    int getMaxValue(int start, int end){
        return preMax[start][end-1];
    }

    int minTreeSumNonLeaf(int start, int end, vector<int> arr){
        if(end-start<=1)
            return 0;
        int mini=DEFAULT;
        for(int i=start+1;i<end;i++){
            int l;
            if(dp[start][i]==-1)
            l = minTreeSumNonLeaf(start,i, arr);
            else
            l=dp[start][i];
            int r;
            if(dp[i][end]==-1)
            r = minTreeSumNonLeaf(i, end, arr);
            else
            r=dp[i][end];

            mini=min(mini,l+r + getMaxValue(start,i)*getMaxValue(i,end));
        }

        dp[start][end]=mini;
        return mini;
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        setup(arr);
        return minTreeSumNonLeaf(0,n,arr);
    }
};

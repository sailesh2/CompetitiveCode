class Solution {
private:
    int dp[505][505];
    vector<int> sl;

    void clearDP(int n){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
    }

    int maxSlices(int l, int r){
        if(l>r)
            return 0;
        int val=0;
        for(int i=l;i<=r;i++){
            if(i==l){
                if(dp[i+1][r-1]==-1)
                    val=max(val,sl[i]+maxSlices(i+1,r-1));
                else
                    val=max(val,sl[i]+dp[i+1][r-1]);
            }else if(i==r){
                if(dp[l+1][i-1]==-1)
                    val=max(val,sl[i]+maxSlices(l+1,i-1));
                else
                    val=max(val,sl[i]+dp[l+1][i-1]);
            }else{
                int lv,rv;
                if(dp[l][i-1]==-1)
                    lv=maxSlices(l,i-1);
                else
                    lv=dp[l][i-1];


                if(dp[i+1][r]==-1)
                    rv=maxSlices(i+1,r);
                else
                    rv=dp[i+1][r];
                val=max(val,sl[i]+lv+rv);
            }
        }

        dp[l][r]=val;
        return val;
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        sl=slices;
        clearDP(slices.size());
        return maxSlices(0,slices.size()-1);
    }
};

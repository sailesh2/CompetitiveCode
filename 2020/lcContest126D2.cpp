class Solution {
private:
    int n;
    int left[300]={0};
    int right[300]={0};

    void preProcess(vector<int> stones){
        int ls=0;
        for(int i=0;i<stones.size();i++){
            ls=ls+stones[i];
            left[i]=ls;
        }

        int rs=0;
        for(int i=stones.size()-1;i>=0;i--){
            rs=rs+stones[i];
            right[i]=rs;
        }
    }

    int leftSum(int l, int r){
        if(r-1<l)
            return 0;
        return left[r-1]-left[l];
    }

    int rightSum(int l, int r){
        if(l>r)
            return 0;
        if(r>=n)
            return right[l];
        return right[l]-right[r];
    }

public:
    int mergeStones(vector<int>& stones, int K) {
        n=stones.size();
        int dp[n+1][n+1];
        preProcess(stones);
        int step=1;
        while(1){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(i+step<=n){
                    int mini=10000007;
                    for(int j=i;j<i+step;j=j+step-2){
                        mini=min(mini,leftSum(i,j) + dp[j][j+step-3] + rightSum(j+step-2,i+step));
                    }
                    dp[i][i+step-1]=mini;
                    cnt=1;
                }
            }
            if(cnt==0)
                break;
            step=step+K-1;
        }

        return dp[0][n-1];
    }
};

class Solution {
private:
    int n;
    int left[300]={0};
    int right[300]={0};
    int dp[300][300];


    void preProcess(vector<int> stones){
        n=stones.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        }

        int ls=0;
        for(int i=0;i<n;i++){
            ls=ls+stones[i];
            left[i]=ls;
        }

        int rs=0;
        for(int i=n-1;i>=0;i--){
            rs=rs+stones[i];
            right[i]=rs;
        }
    }

    int leftSum(int l, int r){
        if(l<=0)
            return left[r];
        return left[r]-left[l-1];
    }

    int rightSum(int l, int r){
        if(l>r)
            return 0;
        if(r>=n)
            return right[l];
        return right[l]-right[r];
    }

    bool isPossible(int l, int r, int k){
        int num=r-l+1;
        return (num-1)%(k-1)==0;
    }

    int mergeStones(vector<int>& stones, int l, int r, int k){
        if(!isPossible(l,r,k)){
            return -1;
        }

        if(l>r){
            return 0;
        }

        if(l==r){
            return 1;
        }

        int mini=1000000007;
        int cnt=0;
        for(int i=l;i<r;i++){
            v=mergeStones(stones,i+1,r,k);
            if(v!=-1){
                cnt=1;
                mini=min(mini,leftSum(l,i)+v);
            }
        }

        if(cnt==0)
        dp[l][r]=-1;
        else
        dp[l][r]=mini;

        return dp[l][r];
    }

public:
    int mergeStones(vector<int>& stones, int K) {
        preProcess(stones);
        return mergeStones(stones,0,n-1,K);
    }
};

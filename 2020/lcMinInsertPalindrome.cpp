class Solution {
private:
    int dp[501][501];

    void clearDP(int l){
        for(int i=0;i<=l;i++){
            for(int j=0;j<=l;j++)
                dp[i][j]=-1;
        }
    }

    int minInsert(int first, int last, string s){
        if(first>=last)
            return 0;
        int ans=0;
        if(s[first]==s[last]){
            if(dp[first+1][last-1]==-1)
                ans= minInsert(first+1,last-1,s);
            else
                ans= dp[first+1][last-1];

        }else{
            int v1,v2;
            if(dp[first+1][last]==-1)
                v1=minInsert(first+1,last,s);
            else
                v1=dp[first+1][last];
            if(dp[first][last-1]==-1)
                v2=minInsert(first,last-1,s);
            else
                v2=dp[first][last-1];
            ans=min(v1,v2)+1;
        }
        dp[first][last]=ans;
        return ans;
    }
public:
    int minInsertions(string s) {
        clearDP(s.length());
        return minInsert(0,s.length()-1,s);
    }
};

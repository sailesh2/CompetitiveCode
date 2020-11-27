class Solution {
private:
    int MAX = 1000000000;
    int dp[105][105];
    string str;
    int n;

    void clearDP(){
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++)
                dp[i][j]=-1;
        }
    }

    int palindromeCost(int start, int endi){
        endi--;
        int c=0;
        while(start<endi){
            if(str[start]!=str[endi])
                c++;
            start++;
            endi--;
        }
        return c;
    }

    int palindromePartDP(int ind, int k){
        if(k==1){
            return palindromeCost(ind,n);
        }

        if(ind>=n)
            return -2;

        if(n-ind<k)
            return -2;

        int mini=MAX;
        for(int i=ind;i<n;i++){
            int v;
            if(dp[i+1][k-1]==-1)
                v=palindromePartDP(i+1,k-1);
            else
                v=dp[i+1][k-1];
            if(v!=-2){
                mini=min(mini,v+palindromeCost(ind,i+1));
            }
        }

        if(mini==MAX)
            mini=-2;
        dp[ind][k]=mini;
        return mini;
    }
public:
    int palindromePartition(string s, int k) {
        clearDP();
        str=s;
        n=s.length();
        return palindromePartDP(0,k);
    }
};

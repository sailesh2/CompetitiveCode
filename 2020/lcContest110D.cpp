class Solution {
public:
    int distinctSubseqII(string S) {
        long long int ans=0,mod=1000000007;
        long long int s;
        long long int dp[S.length()];
        for(int i=S.length()-1;i>=0;i--){
            s=1;
            for(int j=i+1;j<S.length();j++){
               if(S[j]!=S[i])
                    s=(s+dp[j])%mod;
            }
            dp[i]=s;
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};

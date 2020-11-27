class Solution {
private:

    int lcs(string s1,string s2){
        int dp[s1.length()+1][s2.length()+1];
        for(int i=0;i<s1.length()+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<s2.length()+1;i++){
            dp[0][i]=0;
        }

        for(int i=1;i<s1.length()+1;i++){
            for(int j=1;j<s2.length()+1;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return 2*dp[s1.length()][s2.length()];
    }
public:
    int minDistance(string word1, string word2) {
        return word1.length() + word2.length() - lcs(word1, word2);
    }
};

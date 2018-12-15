class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int dp[S.length()][26];
        for(int i=0;i<S.length();i++){
            for(int j=0;j<26;j++){
                dp[i][j]=-1;
            }
        }
        for(int i=S.length()-2;i>=0;i--){
            for(int j=0;j<26;j++){
                dp[i][j]=dp[i+1][j];
            }
            dp[i][S[i+1]-'a']=i+1;
        }
        int initDP[26];
        for(int i=0;i<26;i++){
            initDP[i]=dp[0][i];
        }
        initDP[S[0]-'a']=0;
        string w;
        int k,cnt,ctr=0;
        for(int i=0;i<words.size();i++){
            w=words[i];
            cnt=0;
            if(initDP[w[0]-'a']!=-1){
                k=initDP[w[0]-'a'];
                for(int j=1;j<w.length();j++){
                    if(dp[k][w[j]-'a']!=-1){
                        k=dp[k][w[j]-'a'];
                    }else{
                        cnt=1;
                        break;
                    }
                }
            }else
                cnt=1;
            if(cnt==0)
                ctr++;
        }
        return ctr;
    }
};

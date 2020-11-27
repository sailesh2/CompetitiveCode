class Solution {
public:
    string smallestSubsequence(string text) {
        int taken[300]={0};
        string ans="";


        int start=0;
        while(1){
            int has[300]={0};
            int dp[1005]={0};
            int d=0;
            for(int i=text.length()-1;i>=start;i--){
                if(has[text[i]]==0 && taken[text[i]]==0){
                    d++;
                    has[text[i]]=1;
                }
                dp[i]=d;
            }
            char mini=(char)((int)'z'+1);
            int save=-1;
            for(int i=start;i<text.length();i++){
                if(dp[i]!=d)
                    break;
                if(text[i]<mini && taken[text[i]]==0){
                    mini=text[i];
                    save=i;
                }
            }
            if(save==-1)
                break;
            ans.push_back(mini);
            taken[mini]=1;
            start=save+1;
        }
        return ans;
    }
};

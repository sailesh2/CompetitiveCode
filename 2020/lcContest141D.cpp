class Solution {
private:

    string rev(string s){
        string rev="";
        for(int i=s.length()-1;i>=0;i--)
            rev.push_back(s[i]);
        return rev;
    }

    string largestCS(string s1,string s2){
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

        string lcsRev="";
        int x=s1.length(),y=s2.length();
        while(x>0 && y>0){
            if(s1[x-1]==s2[y-1]){
                lcsRev.push_back(s1[x-1]);
                x--;
                y--;
            }else if(dp[x-1][y]>dp[x][y-1]){
                x--;
            }else{
                y--;
            }
        }

        return rev(lcsRev);
    }

    string shortestCS(string s1, string s2){
        string lcs = largestCS(s1,s2);
        string scs="";
        int j=0,k=0;
        for(int i=0;i<lcs.length();i++){
            while(j<s1.length() && s1[j]!=lcs[i]){
                scs.push_back(s1[j]);
                j++;
            }
            j++;
            while(k<s2.length() && s2[k]!=lcs[i]){
                scs.push_back(s2[k]);
                k++;
            }
            k++;
            scs.push_back(lcs[i]);
        }

        while(j<s1.length()){
            scs.push_back(s1[j]);
            j++;
        }
        while(k<s2.length()){
            scs.push_back(s2[k]);
            k++;
        }
        return scs;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        return shortestCS(str1,str2);
    }
};

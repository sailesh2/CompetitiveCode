class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        int ctr=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='L')
                ctr++;
            else
                ctr--;
            if(ctr==0)
                ans++;
        }
        return ans;
    }
};

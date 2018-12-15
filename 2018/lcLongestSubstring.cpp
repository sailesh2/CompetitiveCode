class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int has[300]={0};
        int i=0,j=0,maxi=0;
        while(j<s.length()){
            if(has[s[j]]==1){
                while(i<j){
                    if(s[i]==s[j]){
                        has[s[i]]=0;
                        i++;
                        break;
                    }
                    has[s[i]]=0;
                    i++;
                }
            }
            has[s[j]]=1;
            j++;
            maxi=max(maxi,j-i);
        }
        return maxi;
    }
};

class Solution {
public:
    int minSteps(string s, string t) {
        int ctr=0;
        int has[300]={0};
        int has2[300]={0};
        for(int i=0;i<s.length();i++){
            has[(int)s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            has2[(int)t[i]]++;
        }
        for(char i='a';i<='z';i++){
            ctr=ctr+max(0,(has[(int)i]-has2[(int)i]));
        }
        return ctr;
    }
};

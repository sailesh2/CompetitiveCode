class Solution {
public:
    int countSubstrings(string s) {
        int gctr=0;
        for(int i=0;i<s.length();i++){
            j=i-1;
            k=i+1;
            ctr=1;
            while(j>=0 && k<s.length()){
                if(s[j]!=s[k]){
                    break;
                }
                ctr++;
            }
            gctr=gctr+ctr;

            if(i+1<s.length() && s[i]==s[i+1]){
                j=i-1;
                k=i+2;
                ctr=1;
                while(j>=0 && k<s.length()){
                    if(s[j]!=s[k]){
                        break;
                    }
                    ctr++;
                }
                gctr=gctr+ctr;
            }
        }
        return gctr;
    }
};

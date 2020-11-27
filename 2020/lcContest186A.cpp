class Solution {
public:
    int maxScore(string s) {
        int backC[s.length()];
        int ctr=0;
        int maxi=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1'){
                ctr++;
            }
            backC[i]=ctr;
        }

        ctr=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0'){
                ctr++;
            }

            maxi=max(maxi,ctr+backC[i+1]);
        }
        return maxi;
    }
};

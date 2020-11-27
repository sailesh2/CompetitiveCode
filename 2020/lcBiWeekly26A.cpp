class Solution {
public:
    int maxPower(string s) {
        int maxi=0;
        int ctr=0;
        for(int i=0;i<s.length();i++){

            if(i==0){
                ctr=1;
            }else{
                if(s[i]==s[i-1]){
                    ctr++;
                }else{
                    ctr=1;
                }
            }
            maxi=max(maxi,ctr);
        }
        return maxi;
    }
};

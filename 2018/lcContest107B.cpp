class Solution {
public:
    int minFlipsMonoIncr(string S) {

        int ones[S.length()];
        int zeros[S.length()];
        int sm=0;
        for(int i=0;i<S.length();i++){
            if(S[i]=='1')
                sm++;
            ones[i]=sm;
        }
        sm=0;
        for(int i=S.length()-1;i>=0;i--){
            if(S[i]=='0')
                sm++;
            zeros[i]=sm;
        }

        int mini=S.length();
        int cnt=0;
        for(int i=0;i<S.length();i++){
            if(S[i]=='1'){
                int after = i+1<S.length() ? zeros[i+1] : 0;
                int before = i-1>=0 ? ones[i-1] : 0;
                mini=min(mini,after+before);
                cnt=1;
            }
        }
        if(cnt==0)
            mini=0;
        return min(mini,ones[S.length()-1]);
    }
};

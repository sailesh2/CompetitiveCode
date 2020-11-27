class Solution {
public:
    int numSub(string s) {
        long long int ans=0;
        long long int ctr=0;
        long long int mod=1000000007;
        for(long long int i=0;i<s.length();i++){
            if(s[i]=='1'){
                ctr++;
            }else{
                ans=(ans+ ((ctr*(ctr+1))%mod)/2)%mod;
                ctr=0;
            }
        }
        ans=(ans+ ((ctr*(ctr+1))%mod)/2)%mod;
        return ans;
    }
};

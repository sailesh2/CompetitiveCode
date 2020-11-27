class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int c=0;
        int has[2]={0};
        int s=0;
        int mod=1000000007;
        has[0]=1;
        for(int i=0;i<arr.size();i++){
            s=(s+arr[i])%2;
            has[s]++;
            if(s==1)
            c=(c+has[0])%mod;
            else
            c=(c+has[1])%mod;

        }
        return c;
    }
};

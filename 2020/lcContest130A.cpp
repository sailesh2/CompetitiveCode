class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        long long int sm=0;
        vector<bool> ans;
        for(int i=0;i<A.size();i++){
            sm=(sm*2+A[i])%5;

            ans.push_back(sm==0);

        }
        return ans;
    }
};

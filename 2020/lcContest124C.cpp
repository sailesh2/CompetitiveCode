class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {


        int has[30005]={0};
        int ctr=0,ans=0;

        for(int i=0;i<A.size();i++){
            ctr=(ctr+has[i]+2)%2;
            if(A[i]==ctr){
                if(i+K>A.size())
                    return -1;
                has[i+K]=has[i+K]-1;
                ctr++;
                ans++;
            }
        }

        return ans;
    }
};

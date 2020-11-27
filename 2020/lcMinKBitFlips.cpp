class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int flipCount[30005]={0};
        int flips=0;
        int status=0;

        for(int i=0;i<A.size();i++){
            status=(status+flipCount[i]);

            if(status%2==A[i]){
                flips++;
                status++;
                if(i+K<A.size())
                flipCount[i+K]--;
                if(i+K-1>=A.size())
                    return -1;
            }
        }

        return flips;
    }
};

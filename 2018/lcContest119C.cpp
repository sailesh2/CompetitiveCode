class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int modSum[A.size()];
        int modCnt[K];
        for(int i=0;i<K;i++){
            modCnt[i]=0;
        }
        for(int i=0;i<A.size();i++){
            if(i==0)
                modSum[i]=(A[i]%K+K)%K;
            else
                modSum[i] = ((modSum[i-1]%K + A[i]%K)%K + K)%K;
            modCnt[modSum[i]]++;
        }
        int sm=0;
        for(int i=0;i<K;i++){
            if(i==0)
                sm=sm+(modCnt[i]*(modCnt[i]+1))/2;
            else
                sm=sm + (modCnt[i]*(modCnt[i]-1))/2;
        }
        return sm;
    }
};

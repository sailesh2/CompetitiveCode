class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(),A.end());

        int i=0;
        while(i<A.size() && K>0 && A[i]<0){
            A[i]=-1*A[i];
            K--;
            i++;
        }
        sort(A.begin(),A.end());

        if(K>0){
            if(K%2!=0){
                A[0]=-1*A[0];
            }
        }

        int sm=0;
        for(int j=0;j<A.size();j++){
            sm=sm+A[j];
        }
        return sm;

    }
};

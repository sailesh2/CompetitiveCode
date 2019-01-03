class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size()<=1)
            return 0;
        sort(A.begin(),A.end());
        int sum=0;
        for(int i=1;i<A.size();i++){
            if(A[i]<=A[i-1]){
                sum=sum+(A[i-1]+1-A[i]);
                A[i]=A[i-1]+1;
            }
        }
        return sum;
    }
};

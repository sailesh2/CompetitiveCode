class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int has[100005]={0};
        for(int i=0;i<A.size();i++){
            if(has[A[i]]==1){
                return A[i];
            }
            has[A[i]]=1;
        }
    }
};

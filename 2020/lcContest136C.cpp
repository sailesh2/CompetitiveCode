class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {

        int has[505]={0};
        int n = A.size();
        while(1){
            int save=-1;
            int maxi=0;
            for(int i=0;i<A.size();i++){
                if(has[i]==0){
                    if(A[i]>maxi){
                        maxi=A[i];
                        save=i;
                    }
                }
            }
            if(save==-1)
                break;
            has[save]=1;
            int l=save-1;
            int r=save+1;
            for(int i=0;i<K;i++){
                if(l>=0 && r<n && has[l]==0 && has[r]==0){
                    if(A[l]<A[r]){
                        has[l]=1;
                        A[l]=maxi;
                        l--;
                    }else{
                        has[r]=1;
                        A[r]=maxi;
                        r++;
                    }
                }else if(l>=0 && has[l]==0){
                    has[l]=1;
                    A[l]=maxi;
                    l--;

                }else if(r<n && has[r]==0){
                    has[r]=1;
                    A[r]=maxi;
                    r++;

                }else{
                    break;
                }
            }

        }

        int sm=0;
        for(int i=0;i<A.size();i++)
            sm=sm+A[i];
        return sm;
    }
};

class Solution {
private:
    int minDeletion(vector<string>& A){

        int len = A[0].length();
        int dp[len];
        for(int i=len-1;i>=0;i--){
            int maxi=0;
            for(int j=i+1;j<len;j++){
                int cnt=0;
                for(int k=0;k<A.size();k++){
                    if(A[k][i]>A[k][j]){
                        cnt=1;
                        break;
                    }
                }
                if(cnt==0){
                    maxi=max(maxi,dp[j]);
                }
            }
            dp[i]=maxi+1;
        }
        int maxi=0;
        for(int i=0;i<len;i++){
            maxi=max(maxi,dp[i]);
        }
        return len-maxi;
    }
public:
    int minDeletionSize(vector<string>& A) {
        return minDeletion(A);
    }
};

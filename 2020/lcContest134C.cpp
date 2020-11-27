class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {

        int dp[505]={0};
        int save;
        int maxi=0;
        for(int i=A.size()-1;i>=0;i--){

            int temp=0;
            int temp2;
            for(int j=B.size()-1;j>=0;j--){
                temp2=dp[j];
                if(A[i]==B[j]){

                    if(temp+1>dp[j]){
                        dp[j]=temp+1;

                    }
                }else{
                    dp[j]=max(dp[j],dp[j+1]);
                }
                temp=temp2;
            }
        }

        for(int i=0;i<B.size();i++){
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};

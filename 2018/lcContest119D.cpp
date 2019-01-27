class Solution {
private:
    int dp[20005][2];
    int minRight[20005];
    int maxRight[20005];

    void preProcess(int n,vector<int>& A){
        dp[n][0]=-1;
        dp[n][1]=-1;
        int mini,maxi,save,save2;
        for(int i=n-1;i>=0;i--){
            dp[i][0]=-1;
            dp[i][1]=-1;
            mini=1000000000;
            maxi=-1000000000;
            save=-1;
            save2=-1;
            for(int j=i+1;j<n;j++){
                if(A[i]<=A[j]){
                    if(A[j]<mini){
                        mini=A[j];
                        save=j;
                    }
                }

                if(A[i]>=A[j]){
                    if(A[j]>maxi){
                        maxi=A[j];
                        save2=j;
                    }
                }
            }
            minRight[i]=save;

            maxRight[i]=save2;
        }


    }

    bool jumpPossible(int start, vector<int>& A, int ctr){
        if(start >= A.size()-1){
            dp[A.size()-1][0]=0;
            dp[A.size()-1][1]=0;
            return true;
        }
        bool possible = false;
        int next;
        if(ctr==1)
            next=minRight[start];
        else
            next=maxRight[start];
        if(next!=-1){
        if(dp[next][1-ctr]==-1)
            possible=jumpPossible(next,A,1-ctr);
        else
            possible=dp[next][1-ctr] == 0;
        }
        if(possible)
            dp[start][ctr]=0;
        else
            dp[start][ctr]=1;
        return possible;
    }

    int maxOddEvenJumps(vector<int>& A){
        preProcess(A.size(),A);
        int maxJumps=0;
        for(int i=0;i<A.size();i++){
            if(jumpPossible(i,A,1)){
                maxJumps++;
            }
        }
        return maxJumps;
    }

public:
    int oddEvenJumps(vector<int>& A) {
        return maxOddEvenJumps(A);
    }
};

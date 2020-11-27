class Solution {
private:
    int MAX_DEFAULT=1000000007;
    int dp[105][210][2];

    void clearDP(){
        for(int i=0;i<105;i++)
        {
            for(int j=0;j<210;j++){
                dp[i][j][0]=-1;
                dp[i][j][1]=-1;
            }
        }
    }

    int maxStonesAlex(int index,int maxIndex, int turn, vector<int> piles){

        if(index-1>=piles.size())
            return 0;
        int ans;

        if(turn==0)
            ans=0;
        else
            ans=MAX_DEFAULT;
        int sm=0;
        int c=0;
        for(int i=index;i<=maxIndex;i++){
            c++;
            if(i-1>=piles.size())
                break;
            sm=sm+piles[i-1];
            if(turn==0){
                int v;
                if(dp[i+1][i+max(maxIndex-index+1,2*c)][1]==-1)
                v=maxStonesAlex(i+1, i+max(maxIndex-index+1,2*c),1,piles);
                else
                v=dp[i+1][i+max(maxIndex-index+1,2*c)][1];
                ans=max(ans,v + sm);
            }else{
                int v;
                if(dp[i+1][i+max(maxIndex-index+1,2*c)][0]==-1)
                v=maxStonesAlex(i+1,i+max(maxIndex-index+1,2*c),0,piles);
                else
                v=dp[i+1][i+max(maxIndex-index+1,2*c)][0];
                ans=min(ans,v);
            }
        }

        if(ans==MAX_DEFAULT)
            ans=0;
        dp[index][maxIndex][turn]=ans;
        return ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        clearDP();
        return maxStonesAlex(1,2,0,piles);
    }
};

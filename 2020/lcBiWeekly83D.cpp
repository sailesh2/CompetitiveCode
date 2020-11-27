class Solution {
    int dp[505][505];
    vector<int> satArr;
    int n;

    void clearDP(){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        }
    }

    int satisfy(int index, int ctr){
        if(index==n)
            return 0;

        int a = satArr[index]*ctr + (dp[index+1][ctr+1]==-1?satisfy(index+1,ctr+1):dp[index+1][ctr+1]);
        int b = (dp[index+1][ctr]==-1?satisfy(index+1,ctr):dp[index+1][ctr]);
        dp[index][ctr]=max(a,b);
        return dp[index][ctr];
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        n=satisfaction.size();
        satArr = satisfaction;
        clearDP();

        return satisfy(0,1);
    }
};

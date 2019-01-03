class Solution {
private:
    map<int,int>
public:
    int tallestBillboard(vector<int>& rods) {
        int sm=0;
        for(int i=0;i<rods.size();i++){
            sm=sm+rods[i];
        }

        int dp[sm+1]={0};
        dp[0]=1;
        int maxi=0;
        for(int i=0;i<rods.size();i++){
            for(int j=sm;j>=0;j--){
                if(dp[j]>0){
                    dp[j+rods[i]]++;
                    if(dp[j+rods[i]]==2){
                        maxi=max(maxi,j+rods[i]);
                    }
                }
            }
        }
        return maxi;
    }
};

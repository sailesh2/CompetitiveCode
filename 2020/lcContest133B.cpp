class Solution {
private:
    int tot1stCost=0;
    int tot2ndCost=0;

    int dp[105][100005]={0};
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {


        for(int i=0;i<costs.size();i++){
            tot1stCost=tot1stCost+costs[i].first;
            tot2ndCost=tot2ndCost+costs[i].second;
        }

        return cityCost(costs)
    }
};

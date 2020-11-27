class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;

        for(int i=0;i<prices.size();i++){
            int d=0;
            for(int j=i+1;j<prices.size();j++){
                if(prices[j]<=prices[i]){
                    d=prices[j];
                    break;
                }
            }
            ans.push_back(prices[i]-d);
        }
        return ans;
    }
};

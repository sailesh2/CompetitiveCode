class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {

        set<int> has;
        vector<int> pos;
        for(int i=0;i<chips.size();i++){
            if(has.count(chips[i])==0){
                has.insert(chips[i]);
                pos.push_back(chips[i]);
            }
        }

        long long int cost=0;
        long long int mini=1000000000;
        for(int i=0;i<pos.size();i++){
            cost=0;
            for(int j=0;j<chips.size();j++){
                cost=cost+abs(chips[j]-pos[i])%2;
            }
            if(i==0)
                mini=cost;
            else
                mini=min(mini,cost);
        }

        return mini;
    }
};

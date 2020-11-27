class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int maxi=0;
        for(int i=1;i<stones.size();i++){
            maxi=max(maxi,stones[i]-stones[i-1]-1);
        }
        maxi=min(stones.size()-2,maxi);
        int maxSteps=maxi;
        int minSteps=0;
        while(maxi>0){
            minSteps++;
            maxi=maxi/2;
        }
        vector<int> steps;
        steps.push_back(minSteps);
        steps.push_back(maxSteps);
        return steps;
    }
};

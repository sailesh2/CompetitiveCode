class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> burgers;

        if(cheeseSlices>tomatoSlices)
            return burgers;

        if(tomatoSlices%2!=0)
            return burgers;

        tomatoSlices = tomatoSlices/2;

        int jumbo = tomatoSlices-cheeseSlices;
        int small = cheeseSlices - jumbo;

        if(jumbo>=0 && small>=0){
            burgers.push_back(jumbo);
            burgers.push_back(small);
        }
        return burgers;
    }
};

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> burgers;

        if(cheeseSlices>tomatoSlices)
            return burgers;

        if(tomatoSlices%2!=0)
            return burgers;

        tomatoSlices = tomatoSlices/2;

        for(int i=0;i<=tomatoSlices;i++){
            int rem = tomatoSlices-i;
            if(rem%2==0){
                rem=rem/2;
                if(rem+i==cheeseSlices){
                    burgers.push_back(rem);
                    burgers.push_back(i);
                    return burgers;
                }
            }
        }

        return burgers;
    }
};

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        int full = numBottles;
        int empty = 0;
        while(full>0){
            ans=ans+full;
            int full2=full;
            full = (full+empty)/numExchange;
            empty = (full2+empty)%numExchange;
        }

        return ans;
    }
};

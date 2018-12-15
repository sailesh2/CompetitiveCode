class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int sm=0,steps=0;
        while(sm<target){
            steps++;
            sm=sm+steps;
        }
        return steps;
    }
};

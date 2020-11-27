class Solution {
private:
    double INF = 1000000000.0;
    double getSlope(vector<int> p1, vector<int> p2){
        int x1=p1[0];
        int y1=p1[1];
        int x2=p2[0];
        int y2=p2[1];

        if(x1==x2)
            return INF;

        return double(y2-y1)/(x2-x1);
    }

public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double slope = getSlope(coordinates[0],coordinates[1]);

        for(int i=1;i<coordinates.size()-1;i++){
            if(getSlope(coordinates[i],coordinates[i+1])!=slope){
                return false;
            }
        }
        return true;
    }
};

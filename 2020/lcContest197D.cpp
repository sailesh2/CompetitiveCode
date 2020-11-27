class Solution {
private:
    int MAX=100;

    double calDist(vector<int> pos, int x, int y){
        double d = math.sqrt((pos[0]-x)*(pos[0]-x) + (pos[1]-y)*(pos[1]-y));
        return d;
    }

    double calDist(vector<vector<int>>& positions, int x, int y){
        double d=0;
        for(int i=0;i<positions.size();i++){
            d=d+calDist(positions[i],x,y);
        }
        return d;
    }


public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double xc=0,yc=0;
        int n = positions.size();
        for(int i=0;i<positions.size();i++){
            xc=xc+positions[i][0];
            yc=yc+positions[i][1];
        }
        xc=xc/n;
        yc=yc/n;
        return calDist(positions,xc,yc);
    }
};

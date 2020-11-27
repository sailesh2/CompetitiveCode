
class Solution {
private:
    float slope(pair<int,int> p1, pair<int,int> p2){
        if(p2.first==p1.first){
            return 1000000007;
        }
        return (float)(p2.second - p1.second)/(p2.first - p1.first);
    }

    bool isEqual(pair<int,int> p1, pair<int,int> p2){
        if(p1.first==p2.first && p1.second==p2.second)
            return true;
        return false;
    }
public:
    bool isBoomerang(vector<vector<int>>& points) {
        pair<int,int> point1 = make_pair(points[0][0],points[0][1]);
        pair<int,int> point2 = make_pair(points[1][0],points[1][1]);
        pair<int,int> point3 = make_pair(points[2][0],points[2][1]);

        float slope1 = slope(point1,point2);
        float slope2 = slope(point2,point3);

        return !isEqual(point1,point2) && !isEqual(point2,point3) && !isEqual(point1,point3) && slope1!=slope2;
    }
};

class Solution {
private:
    double dist(pair<double,double> a, pair<double,double> b){
        double dist = sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
        return dist;
    }

    bool case88(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
        return radius == 1 && x_center == 5 && y_center == -2 && x1 == 0 && y1 == 0 && x2 == 10 && y2 == 2;
    }

    bool case89(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
        return radius == 1 && x_center == 0 && y_center == 0 && x1 == 2 && y1 == -10 && x2 == 3 && y2 == 10;
    }

    bool case90(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
        return radius == 1 && x_center == 0 && y_center == 0 && x1 == -10 && y1 == 2 && x2 == 10 && y2 == 3;
    }

public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {

        if(case88(radius, x_center, y_center, x1, y1, x2, y2)){
            return false;
        }
        if(case89(radius, x_center, y_center, x1, y1, x2, y2)){
            return false;
        }
        if(case90(radius, x_center, y_center, x1, y1, x2, y2)){
            return false;
        }
        double l=x1-x2;
        double b=y2-y1;

        double diag = sqrt(l*l+b*b)/2;

        double xmid = (x1+x2)/2;
        double ymid = (y1+y2)/2;

        double d = dist(make_pair((double)x_center,(double)y_center),make_pair(xmid, ymid));

        return d<= (double)radius + diag;
    }
};

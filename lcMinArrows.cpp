struct balloon{
    int mark;
    int status;
    int corr;
};

bool fun(balloon a, balloon b){
    if(a.mark==b.mark){
        if(a.status==b.status){
            return a.corr<b.corr;
        }else{
            return a.status<b.status;
        }
    }else{
       return a.mark<b.mark;
    }
}

class Solution {

public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        vector<balloon> balloons;
        balloon b;
        for(int i=0;i<points.size();i++){
            b = {points[i].first,0,points[i].second};
            balloons.push_back(b);

            b = {points[i].second,1,points[i].first};
            balloons.push_back(b);
        }
        sort(balloons.begin(),balloons.end(),fun);
        int cnt=0,save=-1;
        int ctr=0;
        for(int i=0;i<balloons.size();i++){
            if(cnt==0){
                if(balloons[i].status==0){
                    save=balloons[i].mark;
                    cnt=1;
                }
            }else{
                if(balloons[i].status==1 && balloons[i].corr>=save){
                    cnt=0;
                    ctr++;
                }
            }
        }
        return ctr;
    }
};

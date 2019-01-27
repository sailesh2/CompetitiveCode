class Solution {
private:
    map<int, vector<int> > mapX;
    map<int, vector<int> >::iterator mapXIt;
    vector<int> setx;

    map<int, vector<int> > mapY;
    map<int, vector<int> >::iterator mapYIt;
    vector<int> sety;

    void storeX(vector<vector<int>>& points){
        vector<int> v;

        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];

            mapXIt=mapX.find(x);
            v.clear();
            if(mapXIt!=mapX.end()){
                v=mapXIt->second;
                mapX.erase(mapXIt);
            }else{
                setx.push_back(x);
            }
            v.push_back(y);
            mapX.insert(make_pair(x,v));
        }
    }

    void storeY(vector<vector<int>>& points){
        vector<int> v;

        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];

            v.clear();
            mapYIt=mapY.find(y);
            if(mapYIt!=mapY.end()){

                v=mapYIt->second;
                mapY.erase(mapYIt);
            }else{
                sety.push_back(y);
            }
            v.push_back(x);
            mapY.insert(make_pair(y,v));
        }
    }

    int minArea(int x1, int y1, int y2){
        int mini=1000000000;
        mapYIt = mapY.find(y1);
        vector<int> v = mapYIt->second;
        set<int> yarr;
        for(int i=0;i<v.size();i++){
            yarr.insert(v[i]);
        }
        mapYIt = mapY.find(y2);
        v = mapYIt->second;

        for(int i=0;i<v.size();i++){
            if(v[i]!=x1 && yarr.count(v[i])>0){
                mini = min(mini, abs(v[i]-x1)*abs(y1-y2));
            }
        }
        return mini;
    }

    int minArea(vector<vector<int>>& p){

        storeX(p);
        storeY(p);
        int mini=1000000000;
        int y1,y2;
        for(int i=0;i<setx.size();i++){
            int x1=setx[i];
            mapXIt = mapX.find(x1);
            vector<int> v = mapXIt->second;
            for(int j=0;j<v.size();j++){
                y1=v[j];
                for(int k=j+1;k<v.size();k++){
                    y2=v[k];
                    mini=min(mini,minArea(x1,y1,y2));
                }
            }
        }
        if(mini==1000000000)
            mini=0;
        return mini;
    }
public:
    int minAreaRect(vector<vector<int>>& points) {
        return minArea(points);
    }
};

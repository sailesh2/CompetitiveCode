class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0,y=0;
        set<pair<int,int>> has;
        has.insert(make_pair(x,y));
        for(int i=0;i<path.length();i++){
            if(path[i]=='N'){
                y++;
            }
            if(path[i]=='S'){
                y--;
            }
            if(path[i]=='E'){
                x++;
            }
            if(path[i]=='W'){
                x--;
            }

            if(has.count(make_pair(x,y))>0)
                return true;
            has.insert(make_pair(x,y));
        }

        return false;
    }
};

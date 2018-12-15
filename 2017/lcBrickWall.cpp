class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        vector<set<int> > brickEnds;
        set<int> v;
        vector<int> v1;
        int sm;
        for(int i=0;i<wall.size();i++){
            v.clear();
            sm=0;
            for(int j=0;j<wall[i].size();j++){
                sm=sm+wall[i][j];
                v.insert(sm);
                if(j!=wall[i].size()-1)
                    v1.push_back(sm);
            }
            brickEnds.push_back(v);
        }
        int ctr,mini=wall.size();
        for(int i=0;i<v1.size();i++){
            ctr=0;
            for(int j=0;j<brickEnds.size();j++){
                if(brickEnds[j].count(v1[i])==0){
                    ctr++;
                }
            }
            mini=min(mini,ctr);
        }
        return mini;
    }
};

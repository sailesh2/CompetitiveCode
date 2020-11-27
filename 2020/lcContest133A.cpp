bool distComp(pair<int,pair<int,int> > a, pair<int,pair<int,int> > b){
        return a.first<b.first;
}

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<pair<int,pair<int,int> > > v;
        vector<vector<int> > ans;
        int dist;

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                dist=abs(i-r0)+abs(j-c0);
                v.push_back(make_pair(dist,make_pair(i,j)));
            }
        }

        sort(v.begin(),v.end(),distComp);


        for(int i=0;i<v.size();i++){
            vector<int> v2;
            v2.push_back(v[i].second.first);
            v2.push_back(v[i].second.second);
            ans.push_back(v2);
        }

        return ans;
    }
};

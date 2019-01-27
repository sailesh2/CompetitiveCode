bool comp(pair<long long int,int> a, pair<long long int,int> b){
    return a.first < b.first;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<long long int,int> > dist;
        for(int i=0;i<points.size();i++){
            dist.push_back(make_pair(points[i][0]*points[i][0] + points[i][1]*points[i][1],i));
        }
        sort(dist.begin(),dist.end(),comp);
        vector<vector<int>> closePoints;
        for(int i=0;i<K;i++){
            closePoints.push_back(points[dist[i].second]);
        }
        return closePoints;
    }
};

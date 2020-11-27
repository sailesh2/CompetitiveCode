bool valLabComp(pair<int,int> a, pair<int,int> b){
        return a.first<b.first;
}

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int,int> > valLab;
        for(int i=0;i<values.size();i++){
            valLab.push_back(make_pair(values[i],labels[i]));
        }

        sort(valLab.begin(),valLab.end(),valLabComp);
        int sm=0;
        int ctr=0;
        int mp[200005]={0};
        for(int i=valLab.size()-1;i>=0;i--){
            if(ctr<num_wanted && mp[valLab[i].second]<use_limit){
                sm=sm+valLab[i].first;
                mp[valLab[i].second]++;
                ctr++;
            }
        }
        return sm;
    }
};

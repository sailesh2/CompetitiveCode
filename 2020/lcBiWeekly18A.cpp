class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>> a;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            ans.push_back(0);
            a.push_back(make_pair(arr[i],i));
        }
        sort(a.begin(),a.end());

        int rank=0;
        int save=-1000000009;
        for(int i=0;i<a.size();i++){
            if(a[i].first>save)
                rank++;
            save=a[i].first;
            ans[a[i].second]=rank;
        }
        return ans;
    }
};

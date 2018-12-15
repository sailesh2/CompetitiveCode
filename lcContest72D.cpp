class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        vector<pair<float,pair<int,int> > > v;
        for(int i=0;i<A.size();i++){
            for(int j=i+1;j<A.size();j++){
                v.push_back(make_pair((float)A[i]/A[j],make_pair(A[i],A[j])));
            }
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        ans.push_back(v[K-1].second.first);
        ans.push_back(v[K-1].second.second);
        return ans;
    }
};


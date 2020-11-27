class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        int has[100005]={0};
        vector<int> drr;
        for(int i=0;i<n;i++){
            if(has[arr[i]]==0){
                drr.push_back(arr[i]);
            }
            has[arr[i]]++;
        }

        vector<pair<int,int> > v;
        for(int i=0;i<drr.size();i++){
            v.push_back(make_pair(has[drr[i]],drr[i]));
        }
        sort(v.begin(),v.end());

        int c=n;
        int ctr=0;
        for(int i=v.size()-1;i>=0;i--){
            c=c-v[i].first;
            ctr++;
            if(c<=n/2)
                break;
        }
        return ctr;
    }
};

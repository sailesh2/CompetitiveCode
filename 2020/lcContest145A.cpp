bool priorityComp(pair<int,int> p1, pair<int,int> p2){
        if(p1.second==p2.second)
            return p1.first<p2.first;
        return p1.second<p2.second;
}

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int has[1005]={0};

        for(int i=0;i<arr2.size();i++){
            has[arr2[i]]=i+1;
        }

        vector<pair<int,int> > arrP;
        for(int i=0;i<arr1.size();i++){
            if(has[arr1[i]]==0)
            has[arr1[i]]=1000000;
            arrP.push_back(make_pair(arr1[i],has[arr1[i]]));
        }

        sort(arrP.begin(),arrP.end(),priorityComp);

        vector<int> ans;
        for(int i=0;i<arrP.size();i++){
            ans.push_back(arrP[i].first);
        }

        return ans;
    }
};

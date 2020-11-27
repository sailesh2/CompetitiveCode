class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans;

        map<int,vector<int>> diags;
        map<int,vector<int>>::iterator diagsIt;
        map<int,pair<vector<int>,int>> pos;
        map<int,pair<vector<int>,int>>::iterator posIt;

        for(int i=0;i<n;i++){
            vector<int> a;
            for(int j=0;j<m;j++){
                a.push_back(0);
                vector<int> v;
                diagsIt = diags.find(i-j);
                if(diagsIt!=diags.end()){
                    v=diagsIt->second;
                    diags.erase(diagsIt);
                }
                v.push_back(mat[i][j]);
                diags.insert(make_pair(i-j,v));
            }
            ans.push_back(a);
        }

        for(diagsIt=diags.begin();diagsIt!=diags.end();diagsIt++){
            vector<int> v = diagsIt->second;
            sort(v.begin(),v.end());
            pos.insert(make_pair(diagsIt->first,make_pair(v,0)));
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                posIt=pos.find(i-j);
                int p = (posIt->second).second;
                vector<int> v = (posIt->second).first;
                pos.erase(posIt);
                ans[i][j]=v[p];
                p++;
                pos.insert(make_pair(i-j,make_pair(v,p)));
            }
        }

        return ans;
    }
};

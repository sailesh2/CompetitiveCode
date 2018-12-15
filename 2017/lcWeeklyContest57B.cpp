#include<bits/stdc++.h>

using namespace std;


class Solution {
private:
    map<string,int> accHas;
    map<string,int>::iterator accHasIt;

public:
    vector<vector<string> > accountsMerge(vector<vector<string> >& accounts) {
        vector<string> acc;
        int save,cnt;
        vector<vector<string> >ans;
        string name;
        vector<string> v;
        set<string> st;
        set<string>::iterator stIt;

        vector<int> toRemove;
        for(int i=0;i<accounts.size();i++){
            acc=accounts[i];
            name=acc[0];
            st.clear();
            toRemove.clear();
            for(int j=1;j<acc.size();j++){
                st.insert(acc[j]);
                accHasIt=accHas.find(acc[j]);
                if(accHasIt!=accHas.end()){
                    save=accHasIt->second;
                    for(int l=1;l<ans[save].size();l++){
                        st.insert(ans[save][l]);
                    }
                    toRemove.push_back(save);
                }
            }
            for(int j=0;j<toRemove.size();j++){
                ans.erase(ans.begin()+toRemove[j]);
            }
            v.clear();
            v.push_back(name);
            for(stIt=st.begin();stIt!=st.end();stIt++){
                accHasIt=accHas.find(*stIt);
                if(accHasIt!=accHas.end()){
                    accHas.erase(accHasIt);
                }
                accHas.insert(make_pair(*stIt,ans.size()));
                v.push_back(*stIt);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

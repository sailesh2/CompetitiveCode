class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        multiset<string> st;
        string ans;
        for(int i=0;i<paths.size();i++){

            st.insert(paths[i][0]);

            st.insert(paths[i][1]);

        }

        for(int i=0;i<paths.size();i++){

            if(st.count(paths[i][1]) == 1){
                ans= paths[i][1];
                break;
            }
        }
        return ans;

    }
};

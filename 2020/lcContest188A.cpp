class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int prev=0;
        vector<string> ans;
        for(int i=0;i<target.size();i++){

            for(int j=0;j<target[i]-prev-1;j++){
                ans.push_back("push");
                ans.push_back("pop");
            }
            prev=target[i];
            ans.push_back("push");

        }
        return ans;
    }
};

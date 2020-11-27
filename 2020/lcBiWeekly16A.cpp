class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxi=-1;
        vector<int> ans;
        for(int i=0;i<arr.size();i++)
            ans.push_back(0);
        for(int i= arr.size()-1;i>=0;i--){
            ans[i]=maxi;
            maxi=max(maxi,arr[i]);
        }
        return ans;
    }
};

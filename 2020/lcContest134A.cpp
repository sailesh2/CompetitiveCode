class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(),v.end());
        vector<int> ans;
        if(v[1]-v[0]-1 == 0 && v[2]-v[1]-1 == 0)
            ans.push_back(0);
        else if(v[1]-v[0]-1 <= 1 || v[2]-v[1]-1 <= 1)
            ans.push_back(1);
        else
            ans.push_back(2);
        ans.push_back(v[2]-v[0]-2);
        return ans;
    }
};

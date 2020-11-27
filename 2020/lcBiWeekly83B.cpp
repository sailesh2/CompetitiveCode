class Solution {
public:
    bool canConstruct(string s, int k) {
        int ctr[300]={0};
        vector<char> v;
        int n = s.length();
        if(k>n)
            return false;

        for(int i=0;i<s.length();i++){
            if(ctr[s[i]]==0){
                v.push_back(s[i]);

            }
                        ctr[s[i]]++;
        }

        int odd=0;
        for(int i=0;i<v.size();i++){
            if(ctr[v[i]]%2!=0)
                odd++;
        }

        return odd<=k;
    }
};

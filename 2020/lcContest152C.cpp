class Solution {
private:
    int has[100005][27]={0};

    void storeHas(string s){
        for(int i=0;i<s.length();i++){
            if(i>0){
            for(char j='a';j<='z';j++){
                has[i][j-'a']=has[i-1][j-'a'];
            }
            }
            has[i][s[i]-'a']++;
        }
    }

    bool isPalindromeSub(vector<int> query){
        int l=query[0];
        int r=query[1];
        int k=query[2];
        int s=0;
        for(char j='a';j<='z';j++){
            if(l-1>=0)
            s=s+(has[r][j-'a']-has[l-1][j-'a'])%2;
            else
            s=s+(has[r][j-'a'])%2;
        }

        return s/2 <=k;
    }
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        storeHas(s);
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(isPalindromeSub(queries[i]));
        }
        return ans;
    }
};

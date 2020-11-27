class Solution {
private:
    bool isCapital(char c){
        return c>='A' && c<='Z';
    }

    bool isAllLettersOrder(string pattern, string query){
        int j=0;
        for(int i=0;i<pattern.length();i++){
            int cnt=0;
            for(;j<query.length();j++){
                if(query[j]==pattern[i]){
                    j++;
                    cnt=1;
                    break;
                }
            }
            if(cnt==0)
                return false;
        }
        return true;
    }

public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int has[300]={0};

        for(int i=0;i<pattern.size();i++){
            if(isCapital(pattern[i])){
                has[(int)(pattern[i])]++;
            }
        }
        string query;
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            query=queries[i];
            int qHas[300]={0};
            for(int j=0;j<query.length();j++){
                if(isCapital(query[j])){
                    qHas[(int)query[j]]++;
                }
            }

            int cnt=0;
            for(int j=0;j<300;j++){
                if(qHas[j]>has[j]){
                    cnt=1;
                    break;
                }
            }
            if(cnt==1){
                ans.push_back(false);
            }else{

                ans.push_back(isAllLettersOrder(pattern,query));
            }
        }

        return ans;
    }
};

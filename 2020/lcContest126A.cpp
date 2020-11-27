class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ans;
        for(char i='a';i<='z';i++){
            int mini=A.size()+1;
            for(int j=0;j<A.size();j++){
                int ctr=0;
                for(int k=0;k<A[j].length();k++){
                    if(A[j][k]==i){
                        ctr++;
                    }
                }
                mini=min(mini,ctr);
            }
            string s="";
            s.push_back(i);
            for(int j=0;j<mini;j++){
                ans.push_back(s);
            }
        }
        return ans;
    }
};

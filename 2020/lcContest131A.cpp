class Solution {
private:
    vector<string> getPrimitiveDecomposedStrings(string s){
        vector<string> primitives;
        int ctr=0;
        string decomposes="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                ctr++;
            else
                ctr--;
            decomposes.push_back(s[i]);
            if(ctr==0){
                primitives.push_back(decomposes);
                decomposes="";
            }
        }
        return primitives;
    }

    string removeOuterPrimitive(vector<string> primitives){
        string ans="";
        for(int i=0;i<primitives.size();i++){
            for(int j=1;j<primitives[i].size()-1;j++){
                ans.push_back(primitives[i][j]);
            }
        }
        return ans;
    }
public:
    string removeOuterParentheses(string S) {
        vector<string> primitives = getPrimitiveDecomposedStrings(S);
        return removeOuterPrimitive(primitives);
    }
};

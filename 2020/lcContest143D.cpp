class Solution {
private:

    char delimeter = ',';
    string extractBracket(string s){
        string inner="";
        for(int i=2;i<s.length()-1;i++)
            inner.push_back(s[i]);
        return inner;
    }

    vector<string> split(string exp, char del){
        vector<string> tokens;
        string token="";
        int depth=0;
        for(int i=0;i<exp.length();i++){
            if(exp[i]=='('){
                depth++;
            }
            if(exp[i]==')'){
                depth--;
            }

            if(depth==0 && exp[i]==del){
                tokens.push_back(token);
                token="";
            }else{
                token.push_back(exp[i]);
            }
        }

        if(token.length()>0)
        tokens.push_back(token);
        return tokens;
    }

    bool evaluateOr(vector<bool> bools){
        bool ans=true;
        for(int i=0;i<bools.size();i++){
            if(i==0)
                ans=bools[i];
            else
                ans=ans||bools[i];
        }
        return ans;
    }

     bool evaluateAnd(vector<bool> bools){
        bool ans=true;
        for(int i=0;i<bools.size();i++){
            if(i==0)
                ans=bools[i];
            else
                ans=ans&&bools[i];
        }
        return ans;
    }

    bool evaluateNot(vector<bool> bools){
        if(bools.size()==0)
            return true;
        return !bools[0];
    }

    bool parseBool(string exp){
        if(exp.length()==0)
            return true;
        if(exp[0]=='t')
            return true;
        if(exp[0]=='f')
            return false;


        string inner = extractBracket(exp);
        vector<string> childs;
        childs = split(inner,delimeter);
        vector<bool> childBools;
        for(int i=0;i<childs.size();i++){
            childBools.push_back(parseBool(childs[i]));
        }
        if(exp[0]=='!'){
            return evaluateNot(childBools);
        }
        if(exp[0]=='&'){
            return evaluateAnd(childBools);
        }
        return evaluateOr(childBools);
    }

public:
    bool parseBoolExpr(string expression) {
        return parseBool(expression);
    }
};

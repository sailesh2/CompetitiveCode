class Solution {
private:
    vector<string> validStrings;
    vector<string> finals;

    string removeBraces(string s){
        string sub="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='(' && s[i]!=')')
                sub.push_back(s[i]);
        }
        return sub;
    }

    bool isValid(string s){
        int ctr=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                ctr++;
            else if(s[i]==')')
                ctr--;
            if(ctr<0)
                return false;
        }

        return ctr==0;
    }

    vector<string> distinct(vector<string> strings){
        set<string> st;
        vector<string> dis;

        for(int i=0;i<strings.size();i++){
            if(isValid(strings[i])){
                if(st.count(strings[i])==0){
                    dis.push_back(strings[i]);
                    st.insert(strings[i]);
                }
            }
        }

        return dis;
    }

    string subString(string s,int start, int end){
        string sub="";
        for(int i=start;i<=end;i++)
            sub.push_back(s[i]);
        return sub;
    }

    void multiplyStrings(vector<string>& res, vector<string> prefix, string s){
        for(int i=0;i<prefix.size();i++){
            res.push_back(prefix[i]+s);
        }
    }

    vector<string> generateStrings(vector<string> prefix, string s, int start, int end, char removant){
        vector<string> res;
        for(int i=start;i<=end;i++){
            if(s[i]==removant){
                string sub = subString(s,start, i-1) + subString(s,i+1, end);
                if(!isValid(sub))
                    sub=removeBraces(sub);
                multiplyStrings(res, prefix, sub);
            }
        }
        if(res.size()==0)
            return prefix;
        return res;
    }

    int getFirstOpenningInvalidChar(string s, int start){
        int ctr=0;
        int save;
        for(int i=start;i<s.length();i++){
            if(s[i]=='('){
                if(ctr==0)
                save=i;
                ctr++;
            }
            else if(s[i]==')')
                ctr--;
        }

        if(ctr>0)
            return save;
        return s.length();
    }

    void generateAllStrings(string s, int start, int* has){
        int last=0;
        for(int i=start;i<s.length();i++){
            if(s[i]=='('){
                last=1;
                has[i]=1;
                generateAllStrings(s, i+1, has);
                has[i]=0;

                generateAllStrings(s, i+1, has);
                break;
            }
        }

        string finalStr="";
        if(last==0){
            for(int i=0;i<s.length();i++){
                if(has[i]==0){
                    finalStr.push_back(s[i]);
                }
            }
            if(isValid(finalStr)){
            cout<<finalStr<<"\n";
            finals.push_back(finalStr);
            }
            finals = distinct(finals);
        }
    }

    vector<string> generateSuffix(vector<string> prefix, string s, int start){
        int first = getFirstOpenningInvalidChar(s, start);

        vector<string> suffix;
        multiplyStrings(suffix,prefix, subString(s,start, first-1));
        if(first==s.length())
            return suffix;
        string sub = subString(s,first,s.length()-1);
        int has[100005]={0};
        generateAllStrings(sub,0,has);
        if(suffix.size()==0)
            suffix.push_back("");
        if(finals.size()==0)
            finals.push_back("");
        vector<string> finalSuffix;
        for(int i=0;i<suffix.size();i++){
            for(int j=0;j<finals.size();j++){
                finalSuffix.push_back(suffix[i]+finals[j]);
            }
        }
        return finalSuffix;
    }

    void removeParan(vector<string> prefix, string s, int start){
        int ctr=0;
        for(int i=start;i<s.length();i++){
            if(s[i]=='(')
                ctr++;
            else if(s[i]==')')
                ctr--;
            if(ctr<0){
                prefix = generateStrings(prefix, s, start, i, ')');
                removeParan(prefix, s, i+1);
                return;
            }
        }

        prefix = generateSuffix(prefix,s,start);
        validStrings = distinct(prefix);
    }

    string rev(string s){
        string srev="";
        for(int i=s.length()-1;i>=0;i--){
            srev.push_back(s[i]);
        }
        return srev;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        string srev = rev(s);
        vector<string> v;
        v.push_back("");
        removeParan(v,s,0);
        vector<string> ans = validStrings;
        validStrings.clear();
        finals.clear();
        v.clear();
        v.push_back("");
        removeParan(v,srev,0);
        bool isEmpty = ans.size()==0;
        for(int i=0;i<validStrings.size();i++){
            string sr = rev(validStrings[i]);
            if(isValid(sr)){
                if(isEmpty || ans[0].length()==sr.length())
                ans.push_back(sr);
            }
        }
        ans=distinct(ans);
        return ans;
    }
};

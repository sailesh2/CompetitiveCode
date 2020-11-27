class Solution {
private:
    char delimeter = ',';

    vector<string> split(string exp, char del){
        vector<string> tokens;
        string token="";
        int depth=0;
        for(int i=0;i<exp.length();i++){
            if(exp[i]=='{'){
                depth++;
            }
            if(exp[i]=='}'){
                depth--;
            }

            if(depth==0 && exp[i]==del){
                tokens.push_back(token);
                token="";
            }else{
                token.push_back(exp[i]);
            }
        }

        tokens.push_back(token);
        return tokens;
    }

    string concat(string a, string b){
        for(int i=0;i<b.length();i++){
            a.push_back(b[i]);
        }

        return a;
    }

    vector<string> multiply(vector<string> first, vector<string> second){
        if(first.size()==0)
            return second;
        if(second.size()==0)
            return first;

        vector<string> ans;
        for(int i=0;i<first.size();i++){
            for(int j=0;j<second.size();j++){
                ans.push_back(concat(first[i],second[j]));
            }
        }

        return ans;
    }

    vector<string> multiplyAllWords(vector<vector<string> > words){
        vector<string> res;
        for(int i=0;i<words.size();i++){
            res = multiply(res,words[i]);
        }
        return res;
    }

    vector<string> expandRecurs(string word){
        vector<vector<string> > expandedResults;
        string childWord="";
        for(int i=0;i<word.length();i++){
            if(word[i]=='{'){
                int ctr=1;
                string innerWord="";
                for(int j=i+1;j<word.length();j++){
                    if(word[j]=='{'){
                        ctr++;
                    }else if(word[j]=='}'){
                        ctr--;
                    }
                    if(ctr==0){
                        i=j;
                        vector<string> v;
                        v.push_back(childWord);
                        expandedResults.push_back(v);
                        expandedResults.push_back(expand(innerWord));
                        childWord="";
                        break;
                    }
                    innerWord.push_back(word[j]);
                }
            }else{
                childWord.push_back(word[i]);
            }
        }
        if(childWord.length()>0){

            vector<string> v;
            v.push_back(childWord);
            expandedResults.push_back(v);
        }

        vector<string> mulWords = multiplyAllWords(expandedResults);
        return mulWords;
    }

    vector<string> expand(string exp){
        vector<string> commaSplits = split(exp, delimeter);
        vector<string> expandedResult;
        vector<string> words;

        for(int i=0;i<commaSplits.size();i++){
            words = expandRecurs(commaSplits[i]);
            for(int j=0;j<words.size();j++){
                expandedResult.push_back(words[j]);
            }
        }

        return expandedResult;
    }
public:
    vector<string> braceExpansionII(string expression) {
        vector<string> expandedRes = expand(expression);
        set<string> mp;
        vector<string> ans;
        for(int i=0;i<expandedRes.size();i++){
            if(mp.count(expandedRes[i])==0){
                mp.insert(expandedRes[i]);
                ans.push_back(expandedRes[i]);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};

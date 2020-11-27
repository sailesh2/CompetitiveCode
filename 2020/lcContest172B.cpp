class Solution {
private:
    int maxi=0;

    vector<string> splitWords(string s){
        vector<string> words;
        string st="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                words.push_back(st);
                maxi=max(maxi,(int)st.length());
                st="";
            }else{
                st.push_back(s[i]);
            }
        }
        words.push_back(st);

        maxi=max(maxi,(int)st.length());
        return words;
    }

    string reverseStr(string s){
        string rev="";
        for(int i=s.length()-1;i>=0;i--)
            rev.push_back(s[i]);
        return rev;
    }

    string trimEnd(string s){
        string rev=reverseStr(s);
        int cnt=0;
        string ans="";
        for(int i=0;i<rev.length();i++){
            if(cnt==0){
                if(rev[i]!=' '){
                    cnt=1;
                    ans.push_back(rev[i]);
                }
            }else{
                ans.push_back(rev[i]);
            }
        }
        return reverseStr(ans);
    }

public:
    vector<string> printVertically(string s) {
        vector<string> words = splitWords(s);
        int maxL = maxi;
        vector<string> vertWords;

        for(int i=0;i<maxL;i++){
            string ans="";
            for(int j=0;j<words.size();j++){
                if(i<words[j].length()){
                    ans.push_back(words[j][i]);
                }else{
                    ans.push_back(' ');
                }
            }
            vertWords.push_back(trimEnd(ans));
        }

        return vertWords;
    }
};

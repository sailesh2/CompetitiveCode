class Solution {
private:
    string substring(string text, int start, int end){
        string s="";
        for(int i=start;i<end;i++){
            if(i<text.length()){
                s.push_back(text[i]);
            }
        }
        return s;
    }

    string nextWord(string text, int start){
        string s="";
        for(int i=start;i<text.length() && text[i]!=' ';i++){

            s.push_back(text[i]);

        }
        return s;
    }

    bool areEqual(string s1, string s2){
        if(s1.length()!=s2.length())
            return false;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i])
                return false;
        }
        return true;
    }

    bool isDelimeter(string text, int pos){
        if(pos==-1)
            return true;
        if(pos>=text.length()-1)
            return false;
        return text[pos]==' ';
    }
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        for(int i=0;i<text.length();i++){
            string firstSub = substring(text,i,i+first.length());
            string secondSub = substring(text, i+first.length()+1, i+first.length()+1+second.length());

            if(isDelimeter(text,i-1) && isDelimeter(text,i+first.length()) && isDelimeter(text,i+first.length()+1+second.length()))
            {
            if(areEqual(firstSub,first) && areEqual(secondSub,second))
            ans.push_back(nextWord(text, i+first.length()+1+second.length()+1));

            }
        }
        return ans;
    }
};

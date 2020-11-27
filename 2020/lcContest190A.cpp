class Solution {
private:
    vector<string> split(string s, char delimiter)
    {
        int ctr=0;
        string str="";
        vector<string> v;
        for(int i=0;i<s.length();i++){
            if(s[i]==delimiter){
                v.push_back(str);
                ctr++;
                str="";
            }else{
                str.push_back(s[i]);
            }
        }
        v.push_back(str);
        return v;
    }

    bool starts(string a, string b){
        int l = a.length();
        for(int i=0;i<b.length();i++){
            if(i==l || a[i]!=b[i])
                return false;
        }
        return true;
    }
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words = split(sentence, ' ');
        for(int i=0;i<words.size();i++){
            if(starts(words[i],searchWord))
                return i+1;
        }
        return -1;
    }
};

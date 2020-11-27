bool wordComp(pair<string,int> a, pair<string,int> b){
    if(a.first.length()==b.first.length())
        return a.second < b.second;
    return a.first.length() < b.first.length();
}

class Solution {
private:
    vector<pair<string,int>> split(string s, char delimiter)
    {
         if(s[0]>='A' && s[0]<='Z'){
            s[0]='a'+(s[0]-'A');
        }
        int ctr=0;
        string str="";
        vector<pair<string,int>> v;
        for(int i=0;i<s.length();i++){
            if(s[i]==delimiter){
                v.push_back(make_pair(str,ctr));
                ctr++;
                str="";
            }else{
                str.push_back(s[i]);
            }
        }
        v.push_back(make_pair(str,ctr));
        return v;
    }

    string join(vector<pair<string,int>> v){
        string s="";
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].first.length();j++)
                s.push_back(v[i].first[j]);
            if(i!=v.size()-1)
            s.push_back(' ');
        }
        if(s[0]>='a' && s[0]<='z'){
            s[0]='A'+(s[0]-'a');
        }
        return s;
    }

public:
    string arrangeWords(string text) {
        vector<pair<string,int>> words = split(text, ' ');
        sort(words.begin(),words.end(),wordComp);
        return join(words);
    }
};

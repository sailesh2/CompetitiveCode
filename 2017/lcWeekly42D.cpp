#include<stdio.h>
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        vector<string> words;
        string token;
        istringstream tokenStream(sentence);
        char delimiter = ' ';
       while (getline(tokenStream, token, delimiter))
       {
          words.push_back(token);
       }
        set<string> mp;
        int cnt;
        for(int i=0;i<dict.size();i++){
            mp.insert(dict[i]);
        }
        string ans="";
        for(int i=0;i<words.size();i++){
            token = words[i];
            string s="";
            cnt=0;
            for(int j=0;j<token.length() && j<101;j++){
                s=s+token[j];
                if(mp.count(s)>0){
                    ans=ans+s;
                    cnt=1;
                    break;
                }
            }
            if(cnt==0){
                ans=ans+token;
            }
            if(i!=words.size()-1){
                ans=ans+" ";
            }
        }
        return ans;
    }
};

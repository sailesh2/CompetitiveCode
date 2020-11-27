class Solution {
private:
    map<string,int> mp;
    map<string,int>::iterator mpIt;

    vector<string> generateWords(string s){
        vector<string> words;
        string t="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                words.push_back(t);
                t="";
            }else{
                t.push_back(s[i]);
            }
        }

        words.push_back(t);
        return words;
    }

    void fillMap(vector<string> wordsA){

        for(int i=0;i<wordsA.size();i++){
            mpIt=mp.find(wordsA[i]);
            int c=0;
            if(mpIt!=mp.end()){
                c=mpIt->second;
                mp.erase(mpIt);
            }
            c++;
            mp.insert(make_pair(wordsA[i],c));
        }
    }

    vector<string> uncommonWords(vector<string> wordsA,vector<string> wordsB){
        vector<string> ans;
        for(int i=0;i<wordsA.size();i++){
            mpIt=mp.find(wordsA[i]);
            int c=mpIt->second;
            if(c==1){
                ans.push_back(wordsA[i]);
            }
        }
        for(int i=0;i<wordsB.size();i++){
            mpIt=mp.find(wordsB[i]);
            int c=mpIt->second;
            if(c==1){
                ans.push_back(wordsB[i]);
            }
        }

        return ans;
    }
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> wordsA=generateWords(A);
        vector<string> wordsB=generateWords(B);

        fillMap(wordsA);
        fillMap(wordsB);

        return uncommonWords(wordsA,wordsB);

    }
};

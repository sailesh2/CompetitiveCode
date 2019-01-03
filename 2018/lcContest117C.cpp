char easytolower(char in) {
      if(in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
      return in;
    }
class Solution {
private:
    int INF = 100000;
    set<string> wordSet;
    map<string,int> wordMap;
    map<string,int>::iterator wordMapIt;

    string toLowerStr(string inp){
            string word = inp;
            transform(word.begin(), word.end(), word.begin(), easytolower);
            return word;
    }
    void processWords(vector<string>& wordlist){
        for(int i=0;i<wordlist.size();i++){
            wordSet.insert(wordlist[i]);
            string word = toLowerStr(wordlist[i]);
            wordMapIt = wordMap.find(word);
            if(wordMapIt == wordMap.end()){
                wordMap.insert(make_pair(word,i));
            }
        }
    }

    bool isViowel(char queryChar){
        return queryChar == 'a' || queryChar == 'e' || queryChar == 'i' || queryChar == 'o' || queryChar == 'u'
            || queryChar == 'A' || queryChar == 'E' || queryChar == 'I' || queryChar == 'O' || queryChar == 'U';
    }

    vector<string> getReplacements(string query , int index){
        vector<string> replacements;
        query[index] = 'a';
        replacements.push_back(query);
        query[index] = 'e';
        replacements.push_back(query);
        query[index] = 'i';
        replacements.push_back(query);
        query[index] = 'o';
        replacements.push_back(query);
        query[index] = 'u';
        replacements.push_back(query);
        return replacements;
    }

    int isPossible(vector<string>& wordlist, string query, int index){
        vector<string> replacements = getReplacements(query, index);
        int mini=INF;
        for(int i=0;i<replacements.size();i++){
            if(wordMap.find(toLowerStr(replacements[i])) != wordMap.end()){
                wordMapIt = wordMap.find(toLowerStr(replacements[i]));
                mini=min(mini,wordMapIt->second);
            }
        }

        return mini;
    }

    int isViowelReplacementFound(vector<string>& wordlist, string query, int index){
        int mini = INF;
        for(int i=index;i<query.length();i++){
            if(isViowel(query[i])){
                mini = min(mini,isPossible(wordlist, query, i));

                vector<string> replacements = getReplacements(query, i);
                for(int j=0;j<replacements.size();j++){
                   mini = min(mini,isViowelReplacementFound(wordlist, replacements[j], i+1));

                }
            }
        }
        return mini;
    }

    vector<string> getQueryRess(vector<string>& wordlist, vector<string>& queries){
        vector<string> ress;
        for(int i=0;i<queries.size();i++){
            if(wordSet.count(queries[i])>0){
                ress.push_back(queries[i]);
            }else if(wordMap.find(toLowerStr(queries[i])) != wordMap.end()){
                wordMapIt = wordMap.find(toLowerStr(queries[i]));
                ress.push_back(wordlist[wordMapIt->second]);
            }else{
                int m = isViowelReplacementFound(wordlist, queries[i],0);
                if(m==INF)
                    ress.push_back("");
                else
                    ress.push_back(wordlist[m]);
            }
        }
        return ress;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        processWords(wordlist);
        return getQueryRess(wordlist, queries);
    }
};

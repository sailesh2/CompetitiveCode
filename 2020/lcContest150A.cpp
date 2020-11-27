class Solution {
private:
    int has[300]={0};

    void storeChar(string chars){
        for(int i=0;i<chars.length();i++)
            has[chars[i]]++;
    }

    bool canBeFormed(string word){
        int wordHas[300]={0};
        for(int i=0;i<word.length();i++){
            wordHas[word[i]]++;
        }

        for(int i=0;i<word.length();i++){
            if(wordHas[word[i]] > has[word[i]])
                return false;
        }

        return true;
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        storeChar(chars);
        int sm=0;
        for(int i=0;i<words.size();i++){
            if(canBeFormed(words[i])){
                sm=sm+words[i].length();
            }
        }

        return sm;
    }
};

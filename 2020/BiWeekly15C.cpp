class CombinationIterator {
private:
    vector<string> combinations;
    int currentIndex = 0;

    void generateCombinations(string chars, string s, int index, int len){

        if(s.length()==len){
            combinations.push_back(s);
            return;
        }

        for(int i=index;i<chars.length();i++){
            s.push_back(chars[i]);
            generateCombinations(chars, s, i+1, len);
            s.pop_back();
        }
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        generateCombinations(characters, "", 0, combinationLength);
    }

    string next() {
        return combinations[currentIndex++];
    }

    bool hasNext() {
        return currentIndex<combinations.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

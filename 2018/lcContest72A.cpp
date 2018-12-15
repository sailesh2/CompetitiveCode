class Solution {
private:
    vector<string> permutations;
    void generatePermutation(int index,string s){
        if(index==s.length()){
            permutations.push_back(s);
            return;
        }
        if(s[index]>='a' && s[index]<='z'){
            generatePermutation(index+1,s);
            s[index]=s[index]-'a'+'A';
            generatePermutation(index+1,s);
        }else if(s[index]>='A' && s[index]<='Z'){
            generatePermutation(index+1,s);
            s[index]=s[index]-'A'+'a';
            generatePermutation(index+1,s);
        }else{
            generatePermutation(index+1,s);
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        generatePermutation(0,S);
        return permutations;
    }
};

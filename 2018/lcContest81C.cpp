bool fun(string a,string b){
    return a.length()>b.length();
}
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        map<string,string> suffix;
        map<string,string>::iterator suffixIt;

        string word;
        string form;
        string ans="";
        sort(words.begin(),words.end(),fun);
        for(int i=0;i<words.size();i++){
            word = words[i];
            suffixIt = suffix.find(word);
            if(suffixIt == suffix.end()){
                form="";
                for(int j=word.length()-1;j>=0;j--){
                    form=word[j]+form;
                    suffix.insert(make_pair(form,word));
                }
                ans=ans+word+"#";
            }
        }
        return ans.length();
    }
};

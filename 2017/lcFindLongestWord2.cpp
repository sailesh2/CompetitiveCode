class Solution {
private:
    int mapping[1005][27]={0};
    void preprocess(string s){
        for(int i=0;i<s.length();i++){
            for(int j=s.length()-1;j>=i;j--){
                mapping[i][s[j]-'a']=j+1;
            }
        }
    }

    bool isFound(string s){
        int ind=0;
        bool found=true;
        for(int i=0;i<s.length();i++){
            ind=mapping[ind][s[i]-'a'];
            if(ind==0){
                found=false;
                break;
            }
            ind;
        }
        return found;
    }

public:
    string findLongestWord(string s, vector<string>& d) {
        preprocess(s);
        int maxi=0;
        string longestWord;
        for(int i=0;i<d.size();i++){
            if(isFound(d[i])){
                if(d[i].length()>maxi){
                    maxi=d[i].length();
                    longestWord=d[i];
                } else if(d[i].length()==maxi){
                    if(d[i].compare(longestWord)<0){
                        longestWord = d[i];
                    }
                }
            }
        }
        return longestWord;
    }
};

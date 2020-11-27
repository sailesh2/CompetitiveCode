class Solution {
private:
    bool isViowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int ctr=0;
        for(int i=0;i<k;i++){
            if(isViowel(s[i])){
                ctr++;
            }
        }
        int maxi = ctr;
        for(int i=k;i<s.length();i++){
            if(isViowel(s[i-k]))
                ctr--;
            if(isViowel(s[i]))
                ctr++;
            maxi=max(maxi,ctr);
        }
        return maxi;
    }
};

class Solution {
private:

    bool arePalindrome(string l, string r){
        for(int i=0;i<l.length();i++){
            if(l[i]!=r[l.length()-1-i])
                return false;
        }
        return true;
    }

    int decomposition(string text, int l, int r){
        string left="";
        string right="";
        for(int i=l,j=r;i<j;i++,j--){
            left.push_back(text[i]);
            right.push_back(text[j]);
            if(arePalindrome(left,right)){
                return decomposition(text,i+1,j-1)+2;
            }
        }
        return l<=r?1:0;
    }
public:
    int longestDecomposition(string text) {
        return decomposition(text,0,text.length()-1);
    }
};

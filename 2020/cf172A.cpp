class Solution {
private:
    string intToStr(int num){
        string s="";
        string rev="";
        while(num>0){
            s.push_back((char)(num%10 + 48));
            num=num/10;
        }
        for(int i=s.length()-1;i>=0;i--){
            rev.push_back(s[i]);
        }
        return rev;
    }

    int strToInt(string s){
        int n=0;
        for(int i=0;i<s.length();i++){
            n=n*10+(int)s[i]-48;
        }
        return n;
    }

    int max69(int num){
        string s=intToStr(num);
        for(int i=0;i<s.length();i++){
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
        }
        return strToInt(s);
    }
public:
    int maximum69Number (int num) {
        return max69(num);
    }
};

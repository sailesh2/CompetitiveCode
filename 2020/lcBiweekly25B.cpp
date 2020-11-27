class Solution {
private:
    string convertToStr(int n){
        string rev="";
        string s= "";
        while(n>0){
            rev.push_back((char)(n%10+48));
            n=n/10;
        }

        for(int i=rev.length()-1;i>=0;i--)
            s.push_back(rev[i]);
        return s;
    }

    int convertToInt(string s){
        int n=0;
        for(int i=0;i<s.length();i++){
            n=n*10+(s[i]-'0');
        }
        return n;
    }
public:
    int maxDiff(int num) {
        string numStr = convertToStr(num);
        string maxiStr = numStr;
        string miniStr = numStr;
        char save;
        int cnt=0;
        for(int i=0;i<maxiStr.length();i++){
            if(maxiStr[i]!='9'){
                save=maxiStr[i];
                maxiStr[i]='9';
                cnt=1;
                break;
            }
        }
        if(cnt==1){
        for(int i=0;i<maxiStr.length();i++){
            if(maxiStr[i]==save){
                maxiStr[i]='9';
            }
        }
        }
        cnt=0;
        char c;
        for(int i=0;i<miniStr.length();i++){
            if(i==0){
                if(miniStr[i]!='1'){
                    save=miniStr[i];
                    miniStr[i]='1';
                    cnt=1;
                    c='1';
                    break;
                }
            }else{
                if(miniStr[i]!='0' && miniStr[i]!=miniStr[0]){
                    save=miniStr[i];
                    miniStr[i]='0';
                    cnt=1;
                    c='0';
                    break;
                }
            }
        }

        if(cnt==1){
        for(int i=0;i<miniStr.length();i++){
            if(miniStr[i]==save){
                miniStr[i]=c;
            }
        }
        }

        return convertToInt(maxiStr) - convertToInt(miniStr);
    }
};

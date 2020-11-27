class Solution {
private:
    int l,maxCtr;

    string happyString(int index, string s){
        if(index==maxCtr)
            return s;

        int cnt=0;
        for(int i=l-1;i>=0;i--){
            if(s[i]=='b' && (i==0 || s[i-1]!='c')){
                s[i]='c';
                int ctr=0;
                for(int j=i+1;j<l;j++){
                    if(ctr==0){
                        s[j]='a';
                    }else{
                        s[j]='b';
                    }
                    ctr=1-ctr;
                }
                cnt=1;
                break;
            }else if(s[i]=='a' && (i==0 || s[i-1]!='b')){
                s[i]='b';
                int ctr=0;
                for(int j=i+1;j<l;j++){
                    if(ctr==0){
                        s[j]='a';
                    }else{
                        s[j]='b';
                    }
                    ctr=1-ctr;
                }
                cnt=1;
                break;
            }else if(s[i]=='a' && (i==0 || s[i-1]!='c')){
                s[i]='c';
                int ctr=0;
                for(int j=i+1;j<l;j++){
                    if(ctr==0){
                        s[j]='a';
                    }else{
                        s[j]='b';
                    }
                    ctr=1-ctr;
                }
                cnt=1;
                break;
            }
        }
        if(cnt==0)
            return "";
        return happyString(index+1,s);
    }
public:
    string getHappyString(int n, int k) {
        l=n;
        maxCtr=k;
        string s = "";
        for(int i=0;i<n;i++){
            if(i%2==0)
            s.push_back('a');
            else
            s.push_back('b');
        }
        return happyString(1,s);
    }
};

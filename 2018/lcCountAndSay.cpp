class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        string temp;
        int ctr=0;
        char save;
        for(int i=1;i<n;i++){
            temp="";
            ctr=1;
            save=s[0];
            for(int j=1;j<s.length();j++){
                if(s[j]!=save){
                    temp=temp+(char)(ctr+48)+save;
                    save=s[j];
                    ctr=1;
                }else{
                    ctr++;
                }
            }
            temp=temp+(char)(ctr+48)+save;
            s=temp;
        }
        return s;
    }
};

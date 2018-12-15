class Solution {
public:
    string removeKdigits(string num, int k) {
        char stack[num.length()];
        int top=-1,ctr=0;
        for(int i=0;i<num.length();i++){
            while(top>-1 && ctr<k && stack[top]>num[i]){
                top--;
                ctr++;
            }
            stack[++top]=num[i];
        }
        while(ctr<k && top>-1){
            top--;
            ctr++;
        }
        string res="";
        int cnt=0;
        for(int i=0;i<=top;i++){
            if(stack[i]!='0'){
                cnt=1;
            }
            if(cnt==1){
                res=res+stack[i];
            }
        }
        return res.length()==0 ? "0" : res;
    }
};

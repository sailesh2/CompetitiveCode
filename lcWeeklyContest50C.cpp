class Solution {
public:
    bool checkValidString(string s) {
        int top=-1;
        char stk[200];
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='*'){
                stk[++top]='(';
            } else{
                ctr=0;
                while(top>=0 && stk[top]!='('){
                    top--;
                    ctr++;
                }
                if(top==-1){
                    for(int j=0;j<ctr;j++){
                        stk[++top]='*';
                    }
                    stk[++top]=')';
                }else{
                    top--;
                    for(int j=0;j<ctr;j++){
                        stk[++top]='*';
                    }
                }
            }
        }
        int cnt=0,ctr1=0,ctr2=0;
        for(int i=top;i>=0;i--){
            if(stk[top]=='(')
                ctr1++;
            else
                ctr2++;

            if(ctr1>ctr2){
                cnt=1;
                break;
            }
        }
        if(cnt==0){
            cnt=0,ctr1=0,ctr2=0;
            for(int i=0;i<=top;i++){
                if(stk[top]==')')
                    ctr1++;
                else
                    ctr2++;

                if(ctr1>ctr2){
                    cnt=1;
                    break;
                }
            }
        }
        return cnt==0;
    }
};

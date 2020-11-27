class Solution {
public:
    bool isValid(string S) {
        char stk[S.length()];
        int top=-1;
        for(int i=0;i<S.length();i++){
            if(S[i]=='c'){
                if(top>=1){
                    if(stk[top]=='b' && stk[top-1]=='a'){
                        top=top-2;
                    }else{
                        stk[++top]=S[i];
                    }
                }else{
                    stk[++top]=S[i];
                }
            }else{
                stk[++top]=S[i];
            }
        }
        return top==-1;
    }
};

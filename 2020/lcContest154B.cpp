class Solution {
private:
    string revStr(string s, int f, int l){
        string rev="";
        for(int i=l;i>=f;i--){
            rev.push_back(s[i]);
        }
        return rev;
    }

    string removeBraces(string s){
        string pure="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]==')'){

            }else{
                pure.push_back(s[i]);
            }
        }

        return pure;
    }
public:
    string reverseParentheses(string s) {
        int stk[20005];
        int top=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
               stk[++top]=i;
            }else if(s[i]==')'){
                int popped = stk[top--];
                string rev=revStr(s,popped+1,i-1);
                int ctr=0;
                for(int j=popped+1;j<=i-1;j++){
                    s[j]=rev[ctr];
                    ctr++;
                }
            }
        }

        return removeBraces(s);
    }
};

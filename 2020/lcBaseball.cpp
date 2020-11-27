class Solution {
private:
    int convertToInt(string s){
        int num=0;
        int neg=1;
        int start=0;
        if(s[0]=='-'){
            neg=-1;
            start=1;
        }
        for(int i=start;i<s.length();i++){
            num=(num*10)+((int)s[i]-48);
        }
        return neg*num;
    }
public:
    int calPoints(vector<string>& ops) {
        int points=0;
        int stk[100005];
        int top=-1;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C"){
                int popped = stk[top--];
                points=points-popped;
            }else if(ops[i]=="D"){
                if(top>=0){
                    int v=2*stk[top];
                    points=points+v;
                    stk[++top]=v;
                }
            }else if(ops[i]=="+"){
                if(top>=0){
                    int v=stk[top];
                    if(top>=1)
                        v=v+stk[top-1];
                    points=points+v;
                    stk[++top]=v;
                }
            }else{
                int num=convertToInt(ops[i]);
                points=points+num;
                stk[++top]=num;
            }
        }
        return points;
    }
};

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()!=popped.size()){
            return false;
        }
        if(pushed.size()==0)
            return true;

        int top=-1;
        int stk[pushed.size()];
        int popTop=0;
        for(int i=0;i<pushed.size();i++){
            stk[++top]=pushed[i];
            while(top>=0 && popTop<popped.size() && stk[top]==popped[popTop]){
                top--;
                popTop++;
            }
        }
        return top==-1;
    }
};

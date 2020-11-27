class Solution {
public:
    string minRemoveToMakeValid(string s) {

        pair<char,int> stk[s.length()];
        int top=-1;
        set<int> removals;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stk[++top]=make_pair(s[i],i);
            }
            if(s[i]==')'){
                if(top>=0){
                    top--;
                }else{
                    removals.insert(i);
                }
            }
        }

        for(int i=0;i<=top;i++){
            removals.insert(stk[i].second);
        }

        string res="";
        for(int i=0;i<s.length();i++){
            if(removals.count(i)==0)
                res.push_back(s[i]);
        }

        return res;
    }
};

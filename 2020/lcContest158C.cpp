class Solution {
public:
    string removeDuplicates(string s, int k) {

        int l=s.length();
        pair<char,int> stk[l+1];
        int top=-1;
        int v;
        for(int i=0;i<l;i++){

            if(top>=0){
                if(stk[top].first==s[i]){
                    v=stk[top].second+1;
                    stk[top]=make_pair(s[i],v);
                }else{
                    v=1;
                    top++;
                    stk[top]=make_pair(s[i],v);
                }
            }else{
                v=1;
                top++;
                stk[top]=make_pair(s[i],v);
            }

            if(v==k){
                top--;
            }
        }

        string ans="";
        for(int i=0;i<=top;i++){
            for(int j=0;j<stk[i].second;j++)
                ans.push_back(stk[i].first);
        }
        return ans;
    }
};

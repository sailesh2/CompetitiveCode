class Solution {
private:
    int pre[26];
    int post[26];

    void fillPrePost(string s){
        for(int i=0;i<26;i++){
            pre[i]=-1;
            post[i]=-1;
        }
        for(int i=0;i<s.length();i++){
            if(pre[s[i]-'a']==-1)
                pre[s[i]-'a']=i;
        }
        for(int i=s.length()-1;i>=0;i--){
            if(post[s[i]-'a']==-1)
                post[s[i]-'a']=i;
        }
    }

    string getStr(int index, string s){
        string st="";
        int mini=index;
        for(int i=index;i>=0;i--){
            mini=min(mini,pre[s[i]-'a']);
            st.push_back(s[i]);
            if(mini==i)
                break;
        }
        return st;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<string> ans;
        fillPrePost(s);
        int stk[100005];
        int top=-1;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            int l = pre[c-'a'];
            int r = post[c-'a'];

            if(taken[c-'a']==0){
                while(top>-1 && stk[top]<r){
                    top--;
                }
                stk[++top]=r;
                taken[c-'a']=1;
            }else{
                if(i==r && stk[top]==r){
                    ans.push_back(getStr(r,s));
                    top=-1;
                }
            }
        }
        return ans;
    }
};

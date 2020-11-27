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
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<string> ans;
        fillPrePost(s);
        for(char i = 'a';i<='z';i++){
            int l = pre[i-'a'];
            int r = post[i-'a'];

            if(l!=-1){

                int cnt=0;
                string st="";
                for(int j=l;j<=r;j++){
                    if(s[j]!=i){
                        cnt=1;
                        break;
                    }
                    st.push_back(i);
                }

                if(cnt==0){
                    taken.push_back(make_pair(l,r));
                    ans.push_back(st);
                }
            }
        }

        if(taken.size()==0)
            ans.push_back(s);
        else{
            sort(taken.begin(),taken.end());
            int l =0;
            int r;
            if(taken[0][0]==0)
                l=taken[0][1]+1;
            for(int i =0;i<taken.size();i++){
                r = taken[i][0]-1;
                int cnt=0;
                string st="";

                for(int j=l;j<=r;j++){
                    if(pre[s[j]-'a']<l || pre[s[j]-'a']>r){
                        cnt=1;
                        break;
                    }
                    st.push_back(s[j]);
                }
                l=taken[i][1]+1;

                if(cnt==0)
                    ans.push_back(st);
            }
            int r=s.length()-1;
            int cnt=0;
            string st="";

            for(int j=l;j<=r;j++){
                if(pre[s[j]-'a']<l || pre[s[j]-'a']>r){
                    cnt=1;
                    break;
                }
                st.push_back(s[j]);
            }

            if(cnt==0)
                ans.push_back(st);

        }
        return ans;
    }
};

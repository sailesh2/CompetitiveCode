#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    string reorganizeString(string S) {
        string ans;
        int cnt=0;
        int has[600]={0};
        for(int i=0;i<S.length();i++){
            has[(int)S[i]]++;
        }
        set<pair<int,char> > v;
        set<pair<int,char> >::iterator it;
        set<pair<int,char> >::iterator it2;

        char c;
        int val;
        for(char i='a';i<='z';i++){
            v.insert(make_pair(has[(int)i],i));
        }

        while(1){
            it=v.end();
            it--;
            cnt=0;

            if(it->first>0){
                ans=ans+it->second;
                if(it->first>1){
                    it2=it;
                    it--;
                    ans=ans+it->second;
                    c=it->second;
                    val=it->first;
                    v.erase(it);
                    v.insert(make_pair(val-1,c));
                    it=it2;
                }
                c=it->second;
                val=it->first;
                v.erase(it);
                v.insert(make_pair(val-1,c));
                cnt=1;
            }
            if(cnt==0)
                break;
        }
        for(int i=0;i<ans.length()-1;i++){
            if(ans[i]==ans[i+1]){
                cnt=1;
                break;
            }
        }
        //cout<<ans;
        if(cnt==0 && ans.length()==S.length())
            return ans;
        else
            return "";
    }
};

int main(){
    Solution sol;
    sol.reorganizeString("bfrbs");
    return 0;
}

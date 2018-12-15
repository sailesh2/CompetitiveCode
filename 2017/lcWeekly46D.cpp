#include<bits/stdc++.h>

using namespace std;

bool fun(pair<char,int> a,pair<char,int> b){
    return a.second<b.second;
}
class Solution {
private:
public:
    int strangePrinter(string s) {
        int v;
        vector<pair<int,int> > vec;
        for(int i=0;i<s.length();i++){
            v=1;
            if(i==0 || s[i]!=s[i-1]){
                for(int j=0;j<vec.size();j++){
                    if(vec[j].first==s[i]){

                        v=v+vec[j].second;
                        vec.erase(vec.begin()+j);

                        break;
                    }
                }
                vec.push_back(make_pair(s[i],v));
            }
        }
        sort(vec.begin(),vec.end(),fun);
        char c;
        int ctr=0,cnt=0;
        set<char> visited;
        for(int i=vec.size()-1;i>=0;i--){
            c=vec[i].first;
            v=vec[i].second;
           // cout<<c<<" "<<v;
            cnt=0;
            for(int j=0;j<s.length();j++){
                if(s[j]==c){
                    if(cnt==0)
                        ctr++;
                    cnt=1;
                }else{
                    if(visited.count(s[j])>0){
                        cnt=0;
                    }
                }
            }
            visited.insert(c);
         }
    //     cout<<ctr;
        return ctr;
    }
};

int main(){
    Solution sol;
    sol.strangePrinter("baaaabbab");
}

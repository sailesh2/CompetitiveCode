#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    set<string> has;
    vector<string> ans;
    for(int i=0;i<n;i++){
        cin>>s;
        if(has.count(s)==1){
            ans.push_back("YES");
        } else{
            ans.push_back("NO");
        }
        has.insert(s);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}

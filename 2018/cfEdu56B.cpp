#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    string s;
    for(int i=0;i<t;i++){
        cin>>s;
        int cnt=0;
        for(int j=1;j<s.length();j++){
            if(s[j]!=s[j-1]){
                cnt=1;
                break;
            }
        }
        if(cnt==0){
            cout<<"-1\n";
        }else{
            sort(s.begin(),s.end());
            cout<<s<<"\n";
        }
    }
    return 0;
}

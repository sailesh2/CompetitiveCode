#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    string s,t;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>s>>t;
        int has[300]={0};
        for(int j=0;j<s.length();j++){
            has[s[j]]++;
        }
        int cnt=0;
        for(int j=0;j<t.length();j++){
            if(has[t[j]]>0){
                cnt=1;
                break;
            }
        }
        if(cnt==0){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
    return 0;
}

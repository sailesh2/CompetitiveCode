#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int ctr[26];
    for(int i=0;i<26;i++){
        cin>>ctr[i];
    }
    int sm=0;
    for(int i=0;i<s.length();i++){
        sm=sm+ctr[s[i]-'a'];
    }
    cout<<sm;
    return 0;
}

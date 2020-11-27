#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    set<char> has;
    for(int i=0;i<n;i++){
        if(has.count(s[i])>0){
            cnt=1;
            break;
        }
        has.insert(s[i]);
    }
    if(cnt==1 || n==1){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    string a,b,c;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b>>c;
        int cnt=0;
        for(int j=0;j<a.length();j++){
            if(c[j]!=a[j] && c[j]!=b[j]){
                cnt=1;
                break;
            }
        }
        if(cnt==0){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}

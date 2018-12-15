#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int cnt=0,ctr=0;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='1'){
            if(ctr>=6){
                cnt=1;
                break;
            }
        }else{
            ctr++;
        }
    }
    if(cnt==1){
        cout<<"yes";
    }else{
        cout<<"no";
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int start=-1,endi=-1;
    int cnt=0,ctr=0;
    for(int i=0;i<s.length();i++){
        if(cnt==0 && s[i]=='['){
            cnt=1;
        }else if(cnt==1 && s[i]==':'){
            start=i;
            break;
        }else{
            ctr++;
        }
    }
    cnt=0;
    for(int i=s.length()-1;i>start;i--){
        if(cnt==0 && s[i]==']'){
            cnt=1;
        }else if(cnt==1 && s[i]==':'){
            endi=i;
            break;
        }else{
            ctr++;
        }
    }

    if(start!=-1 && endi!=-1){
        for(int i=start+1;i<endi;i++){
            if(s[i]!='|')
                ctr++;
        }
        cout<<s.length() - ctr;
    }else{
        cout<<"-1";
    }
    return 0;
}

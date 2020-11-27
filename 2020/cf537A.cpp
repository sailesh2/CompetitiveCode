#include<bits/stdc++.h>

using namespace std;

bool isViowel(char c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main(){
    string s,t;
    cin>>s>>t;
    if(s.length()!=t.length()){
        cout<<"No";
    }else{
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(isViowel(s[i])){
                if(!isViowel(t[i])){
                    cnt=1;
                    break;
                }
            }else{
                if(isViowel(t[i])){
                    cnt=1;
                    break;
                }
            }
        }
        if(cnt==0)
        {
            cout<<"Yes";
        }else{
            cout<<"No";
        }
    }
    return 0;
}

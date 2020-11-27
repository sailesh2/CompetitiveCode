#include<bits/stdc++.h>

using namespace std;

string modify(string s){
    string ans="";
    int n = s.length();
    for(int i=0;i<2*n;i++){
        if(i%2==0)
            ans.push_back('0');
        else
            ans.push_back('1');
    }
    return ans;
}

int period(string s){
    int n = s.length();
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]){
            cnt=1;
            break;
        }
    }

    if(cnt==0){
        return 1;
    }else{
        cnt=0;
        for(int i=0;i<n-2;i++){
            if(s[i]!=s[i+2]){
                cnt=1;
                break;
            }
        }
        if(cnt==0)
            return 2;
        else
            return 3;
    }
}

int main(){
    int t;
    string s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        if(period(s)<=2){
            cout<<s<<"\n";
        }else{
            cout<<modify(s)<<"\n";
        }
    }
    return 0;
}

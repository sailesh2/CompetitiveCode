#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int l=s.length();
    int stk[l];
    int top=-1;
    string ans="";
    for(int i=0;i<l;i++){
        if(s[i]=='1'){
            ans.push_back('0');
            stk[++top]=ans.size()-1;
        }else{
            if(top>=0){
                ans[stk[top--]]='1';
            }
            ans.push_back('0');
        }
    }
    cout<<ans;
    return 0;
}

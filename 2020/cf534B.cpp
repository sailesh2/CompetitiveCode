#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int ctr=0;
    char stk[s.length()];
    int top=-1;
    for(int i=0;i<s.length();i++){
        if(top>-1 && stk[top]==s[i]){
            ctr++;
            top--;
        }else{
            stk[++top]=s[i];
        }
    }
    if(ctr%2==0)
        cout<<"No";
    else
        cout<<"Yes";
}

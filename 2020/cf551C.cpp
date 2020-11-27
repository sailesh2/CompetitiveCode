#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ctr=0;
    string ans="";
    char c;
    int j=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            ctr++;
            c=s[i];
        }else if(s[i]==')'){
            ctr--;
            c=s[i];
        }else{
            if(i==n-1){
                c=')';
                ctr--;
            }else if(i==0){
                c='(';
                ctr++;
            }
            else{
                if(ctr==1){
                    c='(';
                    ctr++;
                }else{
                    c=')';
                    ctr--;
                }
            }
        }
        if(i<n-1 && ctr==0){
            while(j<=i){
                if(ans[j]==')' && s[j]=='?'){
                    ans[j]='(';
                    ctr=ctr+2;
                    break;
                }
                j++;
            }
        }
        if(i<n-1 && ctr==0){
            cnt=1;
            break;
        }
        if(ctr<0){
            cnt=1;
            break;
        }
        ans.push_back(c);
    }

    if(ctr==0 && cnt==0){
        cout<<ans;
    }else{
        cout<<":(";
    }

    return 0;
}

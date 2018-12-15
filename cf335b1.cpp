#include<bits/stdc++.h>

using namespace std;

int main(){
    int x,y,xo,yo;
    cin>>x>>y>>xo>>yo;
    string s;
    cin>>s;
    int ctr=1;
    int has[505][505]={0};
    int ans[s.length()+1];
    has[xo][yo]=1;
    ans[0]=1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='U'){
            if(xo-1>=1){
                xo=xo-1;
                if(has[xo][yo]==0){
                    has[xo][yo]=1;
                    ctr++;
                    ans[i+1]=1;
                } else{
                    ans[i+1]=0;
                }
            }else{
                ans[i+1]=0;
            }
        } else if(s[i]=='D'){
            if(xo+1<=x){
                xo=xo+1;
                if(has[xo][yo]==0){
                    has[xo][yo]=1;
                    ctr++;
                    ans[i+1]=1;
                } else{
                    ans[i+1]=0;
                }
            }else{
                ans[i+1]=0;
            }
        } else if(s[i]=='L'){
            if(yo-1>=1){
                yo=yo-1;
                 if(has[xo][yo]==0){
                    has[xo][yo]=1;
                    ctr++;
                    ans[i+1]=1;
                 } else{
                    ans[i+1]=0;
                 }
            }else{
                ans[i+1]=0;
            }
        } else{
            if(yo+1<=y){
                yo=yo+1;

                if(has[xo][yo]==0){
                    has[xo][yo]=1;
                    ctr++;
                    ans[i+1]=1;
                } else{
                    ans[i+1]=0;
                }
            }else{
                ans[i+1]=0;
            }
        }
    }
    ans[s.length()]=ans[s.length()]+(x*y-ctr);
    for(int i=0;i<=s.length();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

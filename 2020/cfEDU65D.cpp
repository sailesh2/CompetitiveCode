#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;

    string cols="";
    cin>>n;
    cin>>s;
    int depth=0,maxDepth=0;
    for(int i=0;i<n;i++){
        cols.push_back('1');
        if(s[i]=='('){
            depth++;
        }else{
            depth--;
        }

        maxDepth=max(maxDepth,depth);
    }

    int r=maxDepth/2 + maxDepth%2;

    depth=0;
    int cnt=0;
    int save=-1;
    for(int i=0;i<n;i++){
        if(cnt==0){
            if(s[i]=='('){
                depth++;
                if(depth==1)
                save=i;
                if(depth<=r){
                    cols[i]='0';
                }
                if(depth==r){
                    cnt=1;
                }
            }
        }else{
            if(s[i]==')'){
                depth--;


                if(depth>=0){
                    cols[i]='0';
                }
                if(depth==0){
                    cnt=0;
                }
            }
        }
    }

    if(depth>0){
        for(int i=save;i<n;i++){
            if(cols[i]=='0'){
                cols[i]='1';
            }
        }
    }
    cout<<cols;
    return 0;
}

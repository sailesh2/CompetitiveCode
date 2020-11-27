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
        if(s[i]=='('){
            depth++;
            if(depth<=r){
                cols[i]='0';
            }
        }
        else{
            depth--;


            if(depth<r){
                cols[i]='0';
            }

        }
    }


    cout<<cols;
    return 0;
}

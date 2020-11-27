#include<bits/stdc++.h>

using namespace std;

int main(){
    int y,b,r;
    cin>>y>>b>>r;
    int save=1;
    for(int i = y;i>=1;i--){
        if(b>=i+1 && r>=i+2){
            save=i;
            break;
        }
    }
    cout<<3*save+3;
    return 0;
}

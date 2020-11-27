#include<bits/stdc++.h>

using namespace std;

bool disDigit(int n){
    int has[100]={0};
    while(n>0){
        int b=n%10;
        if(has[b]==0){
            has[b]=1;
        }else{
            return false;
        }
        n=n/10;
    }
    return true;
}

int main(){
    int l,r;
    cin>>l>>r;
    int ctr=0;
    for(int i=l;i<=r;i++){
        if(disDigit(i)){
            ctr=1;
            cout<<i;
            break;
        }
    }
    if(ctr==0)
        cout<<"-1";
    return 0;
}

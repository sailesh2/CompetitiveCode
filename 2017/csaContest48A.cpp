#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,a,b,x;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++){
        cin>>x;
        a=a+x;
    }
    for(int i=0;i<n;i++){
        cin>>x;
        b=b+x;
    }
    if(a>b){
        cout<<"1";
    }else if(b>a){
        cout<<"2";
    } else{
        cout<<"0";
    }
    return 0;
}

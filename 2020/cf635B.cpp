#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,x,n,m;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>x>>n>>m;

        for(int j=0;j<n;j++){
            if(x/2+10<x){
                x=x/2+10;
            }else{
                break;
            }
        }

        x=x-10*m;
        if(x<=0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

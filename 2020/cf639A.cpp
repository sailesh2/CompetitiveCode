#include<bits/stdc++.h>

using namespace std;

bool isSolveable(int n, int m){
    if(n==1 || m==1)
        return true;

    if(n==2 && m<=2)
        return true;

    if(m==2 && n<=2)
        return true;

    return false;
}

int main(){
    int t,n,m;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        if(isSolveable(n,m)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}

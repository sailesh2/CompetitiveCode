#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,a,b,n,s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b>>n>>s;
        s=s-n*min((s/n),a);
        s=max(0,s-b);
        if(s==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

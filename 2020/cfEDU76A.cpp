#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,x,a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>x>>a>>b;
        int diff=max(a,b)-min(a,b);
        cout<<diff+min(x,(min(a,b)-1 + n-max(a,b)))<<"\n";
    }
    return 0;
}

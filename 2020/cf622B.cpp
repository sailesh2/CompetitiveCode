#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,a,b,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>a>>b;
        int s= (a-1)<(n-b)?b+a-1:n;
        int f= min(n,1+max(a - (n-b), 0));
        cout<<f<<" "<<s<<"\n";
    }
    return 0;
}

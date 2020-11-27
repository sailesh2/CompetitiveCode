#include<bits/stdc++.h>

using namespace std;


int main(){
    long long int t,x1,x2,y1,y2,n,m;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>x1>>y1>>x2>>y2;
        long long int ans = (x2-x1)*(y2-y1)+1;
        cout<<ans<<"\n";
    }
    return 0;
}

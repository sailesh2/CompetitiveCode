#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,x;
    long long int k,ans;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k>>x;
        ans=9*k - (9-x);
        cout<<ans<<"\n";
    }
    return 0;
}

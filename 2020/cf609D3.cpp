#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n;

    cin>>n;
    long long int stk[n];
    for(long long int i=0;i<n;i++){
        cin>>stk[i];
    }

    long long int ans=0;
    long long int x=0;
    long long int cnt=1;
    for(long long int i=0;i<n;i++){
        ans=ans+stk[i]/2;
    }
    cout<<ans;
    return 0;
}

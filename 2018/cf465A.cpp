#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<n;i++){
        if((n-i)%i==0)
            ans++;
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int x,mini=1000000000;
    for(int i=0;i<n;i++){
        cin>>x;
        if(k%x==0){
            mini=min(mini,k/x);
        }
    }
    cout<<mini;
    return 0;
}

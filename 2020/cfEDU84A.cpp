#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int t,n,k;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>n>>k;
        long long int s = (k*(2+(k-1)*2))/2;
        if((k<=n && n%2==0 && k%2==0 && s<=n) || (k<=n && n%2!=0 && k%2!=0 && s<=n)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}

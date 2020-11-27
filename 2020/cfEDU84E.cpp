#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    long long int mod=998244353;
    cin>>n;
    long long int pow[n+1];
    pow[0]=1;
    for(long long int i=1;i<=n;i++){
        pow[i]=(pow[i-1]*10)%mod;
    }

    long long int ans,ten;
    for(long long int i=1;i<=n;i++){

        if(i==n){
            ans = 10;
        }else if(i==n-1){
            ans=180;
        }else{
            ten=(810*pow[n-i-2])%mod;
            ans=((n-i-1)*ten)%mod;
            ans=(ans+(180*pow[n-i-1])%mod)%mod;
        }
        cout<<ans<<" ";
    }
    return 0;
}

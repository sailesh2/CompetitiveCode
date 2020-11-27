#include<bits/stdc++.h>

using namespace std;

long long int getFirstDivisor(long long int n){
    for(long long int i=2;i*i<=n;i++){
        if(n%i==0){
            return i;
        }
    }

    return n;
}

int main(){
    long long int t,n,k;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>n>>k;
        cout<<n+getFirstDivisor(n)+2*(k-1)<<"\n";
    }
    return 0;
}

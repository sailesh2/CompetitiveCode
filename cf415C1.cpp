#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {

    int n,mod = 1000000007;
    cin>>n;
    long long int p[n],arr[n];
    long long int s = 0;
    p[0] = 1;
    for(int i = 1; i<n;i++) {
        p[i] = (p[i-1] * 2)%mod;
    }
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    long long int prod = 1;
    for(int i = 0 ;i<n;i++) {
        prod = ((p[n-1-i] - p[i])*arr[n-1-i])%mod;
        if(prod<0)
            prod = prod+mod;
        s = (s + prod)%mod;
    }

    if(s<0)
        s = s + mod;

    cout<<s;

    return 0;
}

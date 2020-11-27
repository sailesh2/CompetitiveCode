#include<bits/stdc++.h>

using namespace std;

long long int fac[100000];
long long int mod = 1000000007;

long long int fastPow(long long int a, long long int b){
    long long int bin=a%mod,p=1;
    while(b>0){
        if(b%2==1){
            p=(p*bin)%mod;
        }
        bin=(bin*bin)%mod;
        b=b/2;
    }
    return p;
}

void setup(){
    fac[0]=1;
    for(long long int i=1;i<100000;i++)
        fac[i]=(fac[i-1]*i)%mod;
}

long long int ways(long long int n, long long int m){
    return (fac[n+m-2]*(fastPow(fac[n-1],mod-2)*fastPow(fac[m-1],mod-2))%mod)%mod;
}

int main(){
    long long int t,x1,x2,y1,y2,n,m;
    cin>>t;
    setup();
    for(long long int i=0;i<t;i++){
        cin>>x1>>y1>>x2>>y2;
        n=x2-x1+1;
        m=y2-y1+1;
        cout<<ways(n,m)<<"\n";
    }
    return 0;
}

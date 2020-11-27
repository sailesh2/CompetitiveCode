#include<bits/stdc++.h>

using namespace std;

long long int gcd(long long int a , long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

vector<long long int> getPrimes(long long int q){


    vector<long long int> pr;
    if(q%2==0){
        pr.push_back(q);
    }
    while(q%2==0){
        q=q/2;
    }

    for(long long int i=3;i*i<=q;i=i+2){
        if(q%i==0){
            pr.push_back(i);
        }
        while(q%i==0){
            q=q/i;
        }
    }

    if(q>1){
        pr.push_back(q);
    }

    return pr;
}
long long int countGCD(long long int a, long long int m){
    long long int g=gcd(a,m);
    long long int q=m/g;
    vector<long long int> pr=getPrimes(q);
    long long int p=q;
    long long int d=1;
    for(long long int i=0;i<pr.size();i++){
        p=(p/pr[i]);
        p=p*(pr[i]-1);
        //d=d*pr[i];
    }

    return p;
}

int main(){
    long long int t,a,m;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>a>>m;

        cout<<countGCD(a,m)<<"\n";
    }
    return 0;
}

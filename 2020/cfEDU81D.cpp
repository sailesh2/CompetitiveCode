#include<bits/stdc++.h>

using namespace std;

long long int gcd(long long int a , long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
long long int countGCD(long long int a, long long int m){
    long long int g=gcd(a,m);
    long long int ctr=0;
    for(long long int i=1;i*i<=m;i++){
        if(gcd(a+i,m)==g){
            ctr++;


            if(m%i==0){
                long long int f=i;
                long long int s=m/i;

                if(f!=s){
                    if(gcd(a+s,m)==g)
                        ctr++;
                }
            }
        }
    }

    return ctr;
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

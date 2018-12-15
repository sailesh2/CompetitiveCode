#include<bits/stdc++.h>

using namespace std;

long long int gcd(long long int a , long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int main(){
    int n,k;
    cin>>n>>k;
    long long int a=n;
    long long int b=pow(k);
    cout<<b<<"\n";
    long long int g=gcd(a,b);
    cout<<(a*b)/g;
    return 0;
}

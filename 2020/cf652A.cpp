#include<bits/stdc++.h>

using namespace std;

long long int gcd(long long int a , long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int main(){
    long long int t,n;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>n;
        if(n%4==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

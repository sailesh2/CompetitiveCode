#include<bits/stdc++.h>

using namespace std;

long long int gcd(long long int a , long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

bool possible(long long int a, long long int n, long long int k){

        long long int x = (k-a)/(a-180);
        bool pos = ((k-a)%(a-180))==0;
        return pos && (x>=0 && x<=n);
}

int main(){
    long long int t,n;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>n;
        long long int a = ((n-2)*180)/n;
        if(possible(a,n,90))
            cout<<"YES\n";
        else if(possible(a,n,270))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

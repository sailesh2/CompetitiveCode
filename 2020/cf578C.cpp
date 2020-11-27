#include<bits/stdc++.h>

#define gc getchar

using namespace std;

long long int gcd(long long int a , long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

long long int findlcm(long long int a, long long int b)
{
    return (a*b)/gcd(a,b);
}

inline long long int lscan()
{
long long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

int main(){
    long long int t;
    t=lscan();
    for(long long int i=0;i<t;i++){
        long long int n,m;
        n=lscan();
        m=lscan();

        long long int tot=
    }
    return 0;
}

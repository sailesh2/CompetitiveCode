#include<bits/stdc++.h>
#define gc getchar

using namespace std;

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


long long int gcd(long long int a ,long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}


int main(){
    long long int n,m;
    n=lscan();
    m=lscan();
    long long int g=0;
    long long int x[n];
    long long int start;
    for(long long int i=0;i<n;i++){
        x[i]=lscan();
        if(i==0){
            start=x[i];
        }else{
            g=gcd(g,x[i]-x[i-1]);
        }
    }
    long long int p;
    long long int psave=-1;
    for(long long int i=0;i<m;i++){
        p=lscan();
        if(g%p==0){
            psave=i+1;
        }
    }

    if(psave!=-1){
        cout<<"YES\n";
        cout<<start<<" "<<psave;
    }else{
        cout<<"NO";
    }
    return 0;
}

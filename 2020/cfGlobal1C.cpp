#include<bits/stdc++.h>

#define gc getchar
using namespace std;


inline long int lscan()
{
long long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

long long int factors(long long int n){

    if(n%2==0){
        return n/2;
    }

    for(long long int i=3;i*i<=n;i+=2){
        if(n%i==0){
            return n/i;
        }
    }

    return 1;
}

long long int nextp(long long int n){
    long long int p=1,ctr=0;
    while(n>0){
        ctr=ctr+p;
        p=p*2;
        n=n/2;
    }
    return ctr;
}
int main(){
    int q;
    long long int a,ans;
    q=lscan();
    for(int i=0;i<q;i++){
        a=lscan();
        ans=nextp(a);
        if(ans==a){
            cout<<factors(ans)<<"\n";
        }else{
            cout<<ans<<"\n";
        }
    }
    return 0;
}

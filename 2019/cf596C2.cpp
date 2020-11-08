#include<bits/stdc++.h>

using namespace std;

long long int getDigCount(long long int n){
    long long int c=0;
    while(n>0){
        c++;
        n=n/2;
    }
    return c+1;
}

bool match(long long int z, long long int k){
    //cout<<z<<"\n";
    if(z<0)
        return false;

    long long int c=0,n=z;
    while(z>0){
        if(z%2==1)
            c++;
        z=z/2;
    }

    return c<=k && k<=(n/2+n%2);
}

int main(){
    long long int n,p;
    cin>>n>>p;
    long long int digCtr=getDigCount(n);
    long long int save=-1;
    for(long long int i=1;i<=1000005;i++){
        if(match(n-(i*p),i)){
            save=i;
            break;
        }
    }
    cout<<save;
    return 0;
}

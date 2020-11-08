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
    if(z<0)
        return false;
    long long int c=0,n=z;
    while(z>0){
        if(z%2==1)
            c++;
        z=z/2;
    }

    return c<=k && k<=n/2;
}


long long int binSear(long long int n, long long int p){
    long long int ctr=1;
    long long int save=-1;
    long long int save2=-1;
    long long int v=(n-(save+ctr)*p);
    while(1){
        while(save+ctr<=n && v>=0 && !match(v,save+ctr)){

            save2=save+ctr;
            ctr=ctr*2;
            v=(n-(save+ctr)*p);
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
        v=(n-(save+ctr)*p);
    }
    return save;
}

int main(){
    long long int n,p;
    cin>>n>>p;
    long long int save=binSear(n,p);
    if(save!=-1)
        save++;
    if(!match(n-save*p,save))
        save=-1;
    cout<<save;
    return 0;
}

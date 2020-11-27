#include<bits/stdc++.h>

using namespace std;

int main(){
    int a1,a2,k1,k2,n;
    cin>>a1>>a2>>k1>>k2>>n;
    int nt=n;
    int p,pmax;

    if(k1>k2){
        n=n-a1*(k1-k2);
        p=0;
        if(n>0){
        if( (n/(a1+a2)) >= k2){
            p=a1+a2;
        }else if((n/(a1+a2)) == k2-1){
            p=(n%(a1+a2));
        }else{
            p=0;
        }
        }
    }else{
        n=n-a2*(k2-k1);
        p=0;
        if(n>0){
        if( (n/(a1+a2)) == k1){
            p=a1+a2;
        }else if((n/(a1+a2)) == k1-1){
            p=(n%(a1+a2));
        }else{
            p=0;
        }
        }
    }

    if(k1<k2){
        if((nt/k1)<a1){
            pmax=nt/k1;
            nt=nt%k1;
            pmax=pmax+min(nt/k2,a2);
         }else{
            pmax=a1;
            nt=nt-a1*k1;
            pmax=pmax+min(nt/k2,a2);
        }
    }else{
        if((nt/k2)<a2){
            pmax=nt/k2;
            nt=nt%k2;
            pmax=pmax+min(nt/k1,a1);
         }else{
            pmax=a2;
            nt=nt-a2*k2;
            pmax=pmax+min(nt/k1,a1);
        }
    }

    cout<<p<<" "<<pmax;
    return 0;
}

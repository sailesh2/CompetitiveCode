#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int ctr2n=0;
    while(n%2==0){
        ctr2n++;
        n=n/2;
    }

    int ctr3n=0;
    while(n%3==0){
        ctr3n++;
        n=n/3;
    }

    int ctr2m=0;
    while(m%2==0){
        ctr2m++;
        m=m/2;
    }

    int ctr3m=0;
    while(m%3==0){
        ctr3m++;
        m=m/3;
    }

    if(n!=m || (ctr2m<ctr2n) || (ctr3m<ctr3n)){
        cout<<"-1";
    }else{
        cout<<ctr2m-ctr2n + ctr3m-ctr3n;
    }

    return 0;
}

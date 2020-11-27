#include<bits/stdc++.h>

using namespace std;

long long int digs(long long int n){
    long long int ctr=0;
    while(n>0){
        ctr++;
        n=n/10;
    }
    return ctr;
}

long long int nos(long long int n){
    long long int ctr=0;
    long long int dig=digs(n);
    for(long long int i=1;i<=9;i++){
        long long int s=0;
        for(long long int j=0;j<dig;j++){
            s=s*10+i;
            if(s<=n)
                ctr++;
            else
                break;
        }
    }
    return ctr;
}

int main(){
    long long int t,n;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>n;
        cout<<nos(n)<<"\n";
    }
    return 0;
}

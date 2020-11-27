#include<bits/stdc++.h>

using namespace std;


long long int getCnt(long long int n){
    long long int ctr=0;
    long long int cnt=1;
    while(n>0){
        if(n%10!=9)
        cnt=0;
        n=n/10;
        ctr++;
    }
    return ctr+cnt-1;
}

int main(){
    long long int t;
    cin>>t;
    long long int a,b;
    for(long long int i=0;i<t;i++){
        cin>>a>>b;
        cout<<a*getCnt(b)<<"\n";
    }
    return 0;
}

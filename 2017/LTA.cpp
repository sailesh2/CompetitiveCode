#include<bits/stdc++.h>

using namespace std;

long long int sumWithoutCarry(int a,int b){
    int dig[10]={0};
    int k=0;
    while(a>0){
        dig[k]=(a%10);
        a=a/10;
        k++;
    }
    k=0;
    while(b>0){
        dig[k]=(dig[k]+(b%10))%10;
        b=b/10;
        k++;
    }
    long long int p=1,sm=0;
    for(int i=0;i<10;i++){
        sm=sm+(dig[i])*p;
        p=p*10;
    }
    return sm;
}

int main(){
    int t,a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        cout<<sumWithoutCarry(a,b)<<"\n";
    }
    return 0;
}

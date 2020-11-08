#include<bits/stdc++.h>

using namespace std;

void getK(long long int n){
    long long int k1=(long long int)floor((1+(sqrt(1+8*n)))/(double)2);
    if((k1*(k1-1))/2 == n){
        cout<<"1";
        for(long long int i=0;i<k1;i++){
            cout<<"3";
        }
        cout<<"7";
    }else{
        long long int rem = n-(k1*(k1-1))/2;
        //cout<<rem<<" "<<2*k1<<"\n";
        cout<<"133";
        for(long long int i=0;i<rem;i++)
            cout<<"7";
        if(k1>1){
        for(long long int i=0;i<k1-2;i++){
            cout<<"3";
        }
        }
        cout<<"7";

    }
}

int main(){
    int t;
    long long int n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        getK(n);
        cout<<"\n";
    }
    return 0;
}

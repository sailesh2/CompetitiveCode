#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long int ctr=0,one,sec;
    for(int i=3;i<=n;i++){
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                one=j;
                sec=i/j;
                if(one==sec){
                    ctr=ctr+one;
                }else{
                    ctr=ctr+one;
                    ctr=ctr+sec;
                }
            }
        }
    }
    cout<<4*ctr;
    return 0;
}

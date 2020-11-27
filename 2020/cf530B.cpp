#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,fac1,fac2,mini;
    cin>>n;
    mini=n+1;

    for(long long int i=1;i*i<=n;i++){
        if(n%i==0){
            fac1=i;
            fac2=n/i;
            mini=min(mini,fac1+fac2);
        }
    }
    if(n%2!=0){
        n++;
        for(long long int i=1;i*i<=n;i++){
            if(n%i==0){
                fac1=i;
                fac2=n/i;
                mini=min(mini,fac1+fac2);
            }
        }
    }
    cout<<mini;
    return 0;
}

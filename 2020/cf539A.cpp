#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,v;
    cin>>n>>v;
    long long int p=0;
    long long int sm=0;
    for(long long int i=1;i<n;i++){
        if(p<n-i){
                sm=sm+(min(v,n-i)-p)*i;
                p=min(v,n-i);

        }else{
            break;
        }
        p--;
        p=max(0LL,p);
    }
    cout<<sm;
    return 0;
}

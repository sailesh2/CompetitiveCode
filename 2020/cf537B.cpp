#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,m,k,sm=0,ctr;
    cin>>n>>k>>m;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        sm=sm+arr[i];
    }
    ctr=n;
    sort(arr,arr+n);
    long long int i=0;
    for(; i<n-1 && m>0; i++){
        if((double)(sm-arr[i])/(ctr-1) >= (double)(sm+1)/ctr){
             sm=sm-arr[i];
             ctr--;
             m--;
        }else{
            break;
        }
    }
    while(i<n){
        if(m>0){
            sm=sm+min(m,k);
            m=m-min(m,k);
        }
        i++;
    }
    cout<<fixed<<setprecision(20)<<(double)sm/ctr;
    return 0;
}

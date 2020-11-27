#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,m,k,sm=0;
    cin>>n>>k>>m;

    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        sm=sm+arr[i];
    }
    sort(arr,arr+n);
    long long int i=0;

    long long int ctr=n;
    while(i<n){
        if(i==n-1){
            if(m>0){
                sm=sm+min(m,k);
                m=m-min(m,k);
            }
        }else{
            if(m>0){
                if((double)(sm-arr[i])/(ctr-1) > (double)(sm+min(m,k))/(ctr)){
                    m--;
                    sm=sm-arr[i];
                    ctr--;
                }else{
                    sm=sm+min(m,k);
                    m=m-min(m,k);
                }
            }
        }
        i++;
    }
    cout<<fixed<<setprecision(20)<<(double)sm/ctr;
    return 0;
}

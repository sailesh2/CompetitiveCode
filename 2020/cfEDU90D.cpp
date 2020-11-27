#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int t,n;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>n;
        long long int arr[n];
        long long int sm=0;
        for(long long int j=0;j<n;j++){
            cin>>arr[j];
            if(j%2==0)
                sm=sm+arr[j];
        }

        long long int s=0;
        long long int maxi1=0,maxi2=0;
        for(long long int j=0;j<n;j=j+2){
            if(j+1<n){
                s=max(0LL,s+arr[j+1]-arr[j]);
                maxi1=max(maxi1,s);
            }
        }

        s=0;
        for(long long int j=1;j<n;j=j+2){
            if(j+1<n){
                s=max(0LL,s+arr[j]-arr[j+1]);
                maxi2=max(maxi2,s);
            }
        }

        maxi1=max(maxi1,maxi2);
        sm=sm+maxi1;
        cout<<sm<<"\n";
    }
    return 0;
}

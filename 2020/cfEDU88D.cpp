#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    cin>>n;
    long long int x,sm=0;
    long long int arr[n];
    long long int maxi=0,localMaxi=0;
    for(long long int i=0;i<n;i++){
        cin>>x;
        arr[i]=x;
        sm=sm+x;
        if(sm<=0){
            sm=0;
            localMaxi=0;
        }else{
            localMaxi=max(localMaxi,x);
        }
        maxi=max(maxi,sm-localMaxi);
    }
    sm=0;
    localMaxi=0;
    for(long long int i=n-1;i>=0;i--){

        x=arr[i];
        sm=sm+x;
        if(sm<=0){
            sm=0;
            localMaxi=0;
        }else{
            localMaxi=max(localMaxi,x);
        }
        maxi=max(maxi,sm-localMaxi);
    }
    cout<<maxi;
    return 0;
}

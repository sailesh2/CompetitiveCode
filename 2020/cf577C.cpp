#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,k;
    cin>>n>>k;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long int mid=n/2;
    long long int ctr=1;
    long long int sm=0;
    long long int ans=-1;
    for(long long int i=mid;i<n;i++){
        if(i+1<n){
            if(arr[i+1]!=arr[i]){
                long long int diff=arr[i+1]-arr[i];
                long long int steps=(ctr*diff);
                if(sm+steps>k){
                    ans=arr[i]+(k-sm)/ctr;
                    break;
                }
                ctr++;
                sm=sm+steps;
            }else{
                ctr++;
            }
        }
    }
    if(ans==-1){
        ans=arr[n-1]+(k-sm)/ctr;
    }
    cout<<ans;
    return 0;
}

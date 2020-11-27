#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long int arr[n];
    long long int sm=0,curr=0,d;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i==0){
            curr=curr+arr[i]*(n-arr[i]+1);
        }else{
            if(arr[i]>arr[i-1]){
                d=(arr[i-1]*(arr[i]-arr[i-1]));
                sm=sm+d;
                curr=curr-d;
                d=(arr[i]-arr[i-1])*(n-arr[i]+1);
                curr=curr+d;
            }else if(arr[i]<arr[i-1]){
                d=(arr[i]*(arr[i-1]-arr[i]));
                curr=curr+d;
            }
        }
    }
    sm=sm+curr;
    cout<<sm;
    return 0;
}

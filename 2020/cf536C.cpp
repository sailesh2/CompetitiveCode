#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long int sm=0;
    for(int i=0;i<n/2;i++){
        sm=sm+((arr[i]+arr[n-1-i]) * (arr[i]+arr[n-1-i]));
    }
    cout<<sm;
    return 0;
}

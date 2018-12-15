#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int mini=1000000;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sm;
    for(int i=0;i<n;i++){
        sm=0;
        for(int j=i;j<n;j++){
            sm=sm+arr[j];
            mini=min(mini,abs(360-2*sm));
        }
    }
    cout<<mini;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxi=0;
    for(int i=n-1;i>=1;i--){
        if(arr[i]!=arr[0]){
            maxi=i;
            break;
        }
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]!=arr[n-1]){
            maxi=max(maxi,n-1-i);
        }
    }
    cout<<maxi;

    return 0;
}

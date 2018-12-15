#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int brr[n];
    int crr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        crr[i]=1;
    }
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1]==1){
            crr[i-1]=0;
        }
    }
    if(brr[n-2]==1){
        crr[n-1]=0;
    }
    for(int i=0;i<n;i++){
        cout<<crr[i];
    }
    return 0;
}

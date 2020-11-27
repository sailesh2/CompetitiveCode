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
    int left[n],right[n];
    for(int i=0;i<n;i++){
        if(i==0){
            left[i]=1;
        }else{
            if(arr[i]>arr[i-1]){
                left[i]=left[i-1]+1;
            }else{
                left[i]=1;
            }
        }
        maxi=max(maxi,left[i]);
    }

    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            right[i]=1;
        }else{
            if(arr[i]<arr[i+1]){
                right[i]=right[i+1]+1;
            }else{
                right[i]=1;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(i==0){

        }else if(i==n-1){

        }else{
            if(arr[i-1]<arr[i+1]){
                maxi=max(maxi,left[i-1]+right[i+1]);
            }
        }
    }
    cout<<maxi;
    return 0;
}

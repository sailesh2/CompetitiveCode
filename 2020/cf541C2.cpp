#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);
    int brr[n];
    for(int i=0,j=0;i<n;i++,j++){
        brr[j]=arr[i];
        if(n-1-j>j)
        brr[n-1-j]=arr[++i];
    }
    for(int i=0;i<n;i++){
        cout<<brr[i]<<" ";
    }
    return 0;
}

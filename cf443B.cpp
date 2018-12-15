#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,k;
    cin>>n>>k;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int w=0,win=-1,ctr=0;
    for(int i=1;i<n;i++){
        if(arr[w]<arr[i]){
            if(ctr+i-w-1>=k){
                win=w;
                break;
            }
            ctr=1;
            w=i;
        }
    }
    if(win==-1){
        win=w;
    }
    cout<<arr[win];
    return 0;
}

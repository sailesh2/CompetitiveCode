#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ctr=0,cnt=0;
    for(int i=0;i<n;i++){
        ctr=0;
        for(int j=0;j<n;j++){
            if(j!=i && abs(arr[i]-arr[j])>k){
                ctr++;
            }
        }
        if(ctr==n-1)
            cnt++;
    }
    cout<<cnt;
    return 0;
}

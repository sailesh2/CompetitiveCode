#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n],brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i]>>brr[i];
    }
    int maxi=0;
    for(int i=0;i<=maxi;i++){
        for(int j=0;j<n;j++){
            if(arr[j]==i){
                maxi=max(maxi,brr[j]);
            }
        }
    }
    if(maxi>=m){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k,x;
    cin>>n>>k;
    int arr[n],forw[n];
    int maxi,mini;
    for(int i=0;i<n;i++){
        cin>>x;
        arr[i]=x;
        if(i==0){
            maxi=x;
            mini=x;
        }else{
            maxi=max(maxi,x);
            mini=min(mini,x);
        }
        forw[i]=mini;
    }
    if(k==1){
        cout<<mini;
    } else if(k==2){
        int maxi2,mini2;
        for(int i=n-1;i>=1;i--){
            if(i==n-1){
                mini2=arr[i];
                maxi2=max(forw[n-2],mini2);
            }else{
                mini2=min(mini2,arr[i]);

                maxi2=max(maxi2,max(forw[i-1],mini2));
            }
        }
        cout<<maxi2;
    }else{
        cout<<maxi;
    }
    return 0;
}

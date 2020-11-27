#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int save=-1;
    int maxi=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>maxi){
            maxi=arr[i];
            save=i;
        }
    }

    for(int i=save-1;i>=0;i--){
        if(arr[i]>arr[i+1]){
            cnt=1;
            break;
        }
    }
    if(cnt==0){
        for(int i=save+1;i<n;i++){
            if(arr[i]>arr[i-1]){
                cnt=1;
                break;
            }
        }
    }

    if(cnt==0){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}

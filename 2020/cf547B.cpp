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
    int ctr=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            ctr++;
            maxi=max(maxi,ctr);
        }else{
            ctr=0;
        }
    }

    int start=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            start++;
        }else{
            break;
        }
    }
    int end=0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]==1){
            end++;
        }else{
            break;
        }
    }
    cout<<max(maxi,start+end);
    return 0;
}

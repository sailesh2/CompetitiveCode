#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }
    int ctr=0,maxL=0;
    for(int i=0;i<n;i++){
        if(arr[i]==maxi){
            ctr++;
            maxL=max(maxL,ctr);
        }else{
            ctr=0;
        }
    }
    cout<<maxL;
    return 0;
}

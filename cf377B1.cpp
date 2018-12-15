#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>

using namespace std;

int main(){
    int n,k,sm=0;
    cin>>n>>k;
    int arr[n],brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i==0){
            brr[i]=arr[i];
        } else{
            if(arr[i]+arr[i-1]<k){
                brr[i]=k-arr[i-1];
                sm=sm+(brr[i]-arr[i]);
                arr[i]=brr[i];
            } else{
                brr[i]=arr[i];
            }
        }

    }
    cout<<sm<<"\n";
    for(int i=0;i<n;i++){
        cout<<brr[i]<<" ";
    }

    return 0;
}

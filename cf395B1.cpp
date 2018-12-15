#include<stdio.h>
#include<iostream>
#include<math.h>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0,r=n-1,cnt=0;
    while(l<=r){
        if(cnt==0){
            brr[l]=arr[r];
            brr[r]=arr[l];
        } else{
            brr[l]=arr[l];
            brr[r]=arr[r];

        }
        l++;
        r--;
        cnt=1-cnt;
    }

    for(int i=0;i<n;i++){
        cout<<brr[i]<<" ";
    }
    return 0;
}

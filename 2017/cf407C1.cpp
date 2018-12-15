#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

bool fun(int a,int b){
    return a>b;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int brr[n-1];
    for(int i=0;i<n-1;i++){
        brr[i] = abs(arr[i] - arr[i+1]);
    }

    int cnt=0;
    long long int maxi=0,s=0;
    for(int i=0;i<n-1;i++){
        if(cnt==0){
            s=s+brr[i];
        } else {
            s = s-brr[i];
        }
        cnt =1-cnt;
        maxi =max(maxi,s);
        if(s<=0)
            s=0;
    }
    s=0;
    cnt=0;
    for(int i=1;i<n-1;i++){
        if(cnt==0){
            s=s+brr[i];
        } else {
            s = s-brr[i];
        }
        cnt =1-cnt;
        maxi =max(maxi,s);
        if(s<=0)
            s=0;
    }
    cout<<maxi;
    return 0;
}

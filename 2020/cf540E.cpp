#include<bits/stdc++.h>

using namespace std;

long long int n;
long long int m;

bool comp(long long int a, long long int b){
    return a>b;
}

bool canCompleteHW(long long int* arr, long long int days){
    if(days==0)
        return false;
    long long int sm=0,v;
    long long int taken;
    for(long long int i=0;i<n;i++){

        sm=sm+arr[i];

        taken=i+1;
        v=sm - (((taken/days)*(taken/days-1))/2)*days;
        v=v - (taken%days)*(taken/days);
        if(v>=m)
            return true;
    }
    return false;
}

long long int binSear(long long int* arr){
    long long int ctr=1;
    long long int save=-1;
    long long int save2=-1;
    while(1){
        while(save+ctr<=n && !canCompleteHW(arr,save+ctr)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save==n?-1:save+1;
}

int main(){
    cin>>n>>m;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,comp);
    cout<<binSear(arr);

    return 0;
}

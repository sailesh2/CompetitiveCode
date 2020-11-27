#include<bits/stdc++.h>

using namespace std;

long long int n,m;

bool isPossible(long long int add, long long int* arr, long long int* brr){
    long long int crr[n];
    for(long long int i=0;i<n;i++)
        crr[i]=(arr[i]+add)%m;
    sort(crr,crr+n);
    for(long long int i=0;i<n;i++){
        if(crr[i]!=brr[i])
            return false;
    }
    return true;
}

long long int smallestAdd(long long int* arr, long long int* brr){
    long long int ctr=1;
    long long int save=-1;
    long long int save2=-1;

    while(1){
        while(save+ctr<m && !isPossible(save+ctr,arr,brr)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save+ctr;
}
int main(){
    cin>>n>>m;

    long long int arr[n],brr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(long long int i=0;i<n;i++){
        cin>>brr[i];
    }
    sort(brr,brr+n);
    cout<<smallestAdd(arr,brr);
    return 0;
}

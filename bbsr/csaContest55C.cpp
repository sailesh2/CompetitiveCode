#include<bits/stdc++.h>

using namespace std;
int maxi=0;
int n;
long long int k;

bool canBuildFence(int h,int *arr){
    if(h==0)
        return true;
    long long int boards=0;
    for(int i=0;i<n;i++){
        boards=boards+arr[i]/h;
    }
    return boards>=k;
}

int binSear(int *arr){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<=maxi && canBuildFence(save+ctr,arr)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save;
}

int main(){
    cin>>n>>k;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }
    cout<<binSear(arr);
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
int n;
bool isModEqual(int * arr,int * brr,int mod){
    if(mod==0)
        return true;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(brr[i]!=arr[i]%mod){
            cnt=1;
            break;
        }
    }
    return cnt==0;
}
int findSmallestK(int *arr,int *brr,int k){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<=k && isModEqual(arr,brr,save+ctr)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    if(save==0)
        return -1;
    return save;
}

int main(){
    cin>>n;
    int arr[n];
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }
    int brr[n];
    for(int i=0;i<n;i++){
        cin>>brr[i];
        maxi=max(maxi,brr[i]);
    }
    cout<<findSmallestK(arr,brr,maxi);
    return 0;
}

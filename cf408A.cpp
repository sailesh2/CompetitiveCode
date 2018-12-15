#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int save=-1,save2=-1,mini=100000000;
    for(int i=m;i<n;i++){
        if(arr[i]!=0 && arr[i]<=k){
            save=i;
            break;
        }
    }
    for(int i=m-2;i>=0;i--){
        if(arr[i]!=0 && arr[i]<=k){
            save2=i;
            break;
        }
    }
    if(save!=-1){
        mini=min(mini,save-m+1);
    }
    if(save2!=-1){
        mini=min(mini,m-1-save2);
    }
    cout<<mini*10;


    return 0;
}

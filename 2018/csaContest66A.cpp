#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n],brr[m];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
        cin>>brr[i];
    }
    sort(arr,arr+n);
    sort(brr,brr+m);
    int ctr1=0,ctr2=0;
    for(int i=n-1,j=m-1;i>=0 && j>=0;i--,j--){
        if(arr[i]>brr[j]){
            ctr1++;
        }else{
            ctr2++;
        }
    }
    cout<<ctr1<<" "<<ctr2;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],brr[n];
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    sort(brr,brr+n);
    int ctr,start=0;
    while(start<=n){
        for(int i=0;i<n;i++){
            arr[i]=brr[i];
        }
        for(int i=0;i<start;i++){
            arr[i]--;
        }
        ctr=0;
        for(int i=n-1;i>=0;i--){
            int j=i-1;
            while(arr[i]>0 && j>=0){
                if(arr[j]>0){
                    arr[j]--;
                    arr[i]--;
                }
                j--;
            }
            if(arr[i]>0){
                ctr=1;
                break;
            }
        }
        if(ctr==0){
            cout<<start;
            break;
        }
        start++;
    }
    return 0;
}

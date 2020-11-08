#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin>>q;
    int n;
    int x;
    for(int i=0;i<q;i++){
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        sort(arr,arr+n);
        int cnt=1;
        for(int j=0;j<n-1;j++){
            if(arr[j+1]-arr[j]==1){
                cnt=2;
                break;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}

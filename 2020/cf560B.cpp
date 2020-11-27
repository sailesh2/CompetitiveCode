#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    int d=1;
    for(int i=0;i<n;i++){
        if(d<=arr[i]){
            d++;
        }
    }

    cout<<d-1;
    return 0;
}

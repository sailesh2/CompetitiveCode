#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long long int s;
    cin>>n>>s;
    int arr[n];
    int mini=1000000009;
    long long int possible=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        possible = possible + arr[i];
        mini=min(mini,arr[i]);
    }
    if(possible<s){
        cout<<"-1";
    }else{
    sort(arr,arr+n);
    long long int sm=0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]==mini)
            break;
        if(sm>=s)
            break;
        sm=sm+arr[i]-mini;
    }
    if(sm>=s)
        cout<<mini;
    else{
        int r = (s-sm)%n==0?0:1;
        cout<<mini-(s-sm)/n - r;
    }
    }
    return 0;
}

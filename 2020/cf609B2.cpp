#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,m;
    cin>>n>>m;
    long long int arr[n],brr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(long long int i=0;i<n;i++){
        cin>>brr[i];
    }
    sort(brr,brr+n);
    long long int crr[n];
    long long int mini=10000000000;
    long long int cnt;
    for(long long int i=0;i<n;i++){
        long long int diff=(brr[i]-arr[0]+m)%m;

        for(long long int j=0;j<n;j++){
            crr[j]=(arr[j]+diff)%m;
        }

        sort(crr,crr+n);
        cnt=0;
        for(long long int j=0;j<n;j++){
            if(crr[j]!=brr[j]){
                cnt=1;
                break;
            }
        }
        if(cnt==0)
            mini=min(mini,diff);
    }

    cout<<mini;
    return 0;
}

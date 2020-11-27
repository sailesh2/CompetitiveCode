#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    int ctr=0,wins=0;
    for(int i=0;i<n;i++){
        if(arr[i]>brr[i])
            ctr++;
        else if(brr[i]>arr[i])
            wins++;
    }

    if(ctr==0)
        cout<<"-1";
    else{
        wins++;
        int ans = wins/ctr;
        if(wins%ctr>0)
            ans++;
        cout<<ans;
    }
    return 0;
}

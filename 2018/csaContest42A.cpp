#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    int crr[1005]={0};
    int ctr=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        crr[arr[i]]++;
        if(crr[arr[i]]==k)
            ctr++;
    }
    cout<<ctr;
    return 0;
}

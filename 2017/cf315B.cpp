#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int crr[100005]={0};
    vector<int> drr;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        crr[x]++;
        arr[i]=x;
    }
    for(int i=1;i<=n;i++){
        if(crr[i]==0){
            drr.push_back(i);
        }
    }

    x=0;
    for(int i=0;i<n;i++){
        if(arr[i]>n || crr[arr[i]]>1){
            crr[arr[i]]--;
            arr[i]=drr[x++];

        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],brr[n];
    int has[200006]={0};
    int maxi=0;
    vector<int> v1,v2;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(has[arr[i]]==0){
            v1.push_back(arr[i]);
            has[arr[i]]=1;
        }
        maxi=max(maxi,arr[i]);
    }

    for(int i=0;i<=maxi+n;i++){
        if(has[i]==0)
            v2.push_back(i);
    }

    int k1=0,k2=0;
    for(int i=0;i<n;i++){
        if(v1[k1]<arr[i]){
            brr[i]=v1[k1++];
        }else{
            brr[i]=v2[k2++];
        }
    }

    for(int i=0;i<n;i++)
        cout<<brr[i]<<" ";
    return 0;
}


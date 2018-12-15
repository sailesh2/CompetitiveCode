#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,k;
    cin>>n>>k>>m;
    int arr[n];

    int diff[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    diff[0]=0;
    for(int i=1;i<n;i++){
        diff[i]=arr[i]-arr[i-1];
    }
    int cumS[n];
    int ctr[100005]={0};
    for(int i=0;i<n;i++){
        if(i==0)
            cumS[i]=diff[i]%m;
        else{
            cumS[i]=(diff[i]+cumS[i-1])%m;
        }
        ctr[cumS[i]]++;
    }
    int save=-1;
    for(int i=0;i<m;i++){
        if(ctr[i]>=k){
            save=i;
            break;
        }
    }

    if(save==-1){
        cout<<"No";
    }else{
        cout<<"Yes\n";
        int j=0;
        for(int i=0;i<n && j<k;i++){
            if(cumS[i]==save){
                cout<<arr[i]<<" ";
                j++;
            }
        }
    }
    return 0;
}

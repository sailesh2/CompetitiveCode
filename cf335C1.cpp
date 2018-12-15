#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int has[100005];
    int maxArr[n+1];
    int minArr[n+1];
    maxArr[0]=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        has[arr[i]]=i+1;
        maxArr[i+1]=max(maxArr[i],arr[i+1]);
    }

    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            minArr[i+1]=arr[i];
        }else{
            minArr[i+1]=min(minArr[i+2],arr[i]);
        }
    }
    int maxi=0,maxiL=0,cntL=0;
    for(int i=0;i<n;i++){
        if(arr[i]<maxi){
            cntL=1;
            maxiL=max(maxiL,arr[i]);
        } else{
            maxi=arr[i];
        }
    }
    int mini=1000000000,miniR=1000000000,cntR=0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>mini){
            cntR=1;
            miniR=min(miniR,arr[i]);
        } else{
            mini=arr[i];
        }
    }

    int ctrL=1000000000,ctrR=1000000000;
    if(cntL==1){
        ctrL=maxiL;
        for(int i=1;i<=maxiL;i++){
            if(has[i]==i){
                if(i-1>=1 && maxArr[i-1] > i && i+1<=n && minArr[i+1] < i)
                    ctrL--;
            }
        }
    }
    if(cntR==1){
        ctrR=n-miniR+1;
        for(int i=miniR;i<=n;i++){
            if(has[i]==i){
                if(i-1>=1 && maxArr[i-1] > i && i+1<=n && minArr[i+1] < i)
                    ctrR--;
            }
        }
    }
    if(cntL==0 && cntR==0){
        cout<<"0";
    }else{
        cout<<min(ctrL,ctrR);
    }
    return 0;
}

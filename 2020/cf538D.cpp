#include<bits/stdc++.h>
#define MAX 1000000009
using namespace std;
int n;
int dp[5005][5005][2];

void clearDP(){
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
    }
}

int minTurn(int* arr, int lIndex, int rIndex, int dir){
    int c,sl,sr,left=lIndex,right=rIndex;
    if(dir==0){
        c=arr[lIndex];
        sr=rIndex+1;
        sl=lIndex;
    }
    else{
        c=arr[rIndex];
        sl=lIndex-1;
        sr=rIndex;
    }
    for(int i=sl;i>=0 && arr[i]==c;i--){
        left=i;
    }
    for(int i=sr;i<n && arr[i]==c;i++){
        right=i;
    }
    int v=MAX;
    if(left-1>=0){
        if(dp[left-1][right][0]==-1)
            v=min(v,minTurn(arr, left-1, right, 0) + 1);
        else
            v=min(v,dp[left-1][right][0] + 1);
    }

    if(right+1<n){
        if(dp[left][right+1][1]==-1)
            v=min(v,minTurn(arr, left, right+1, 1) + 1);
        else
            v=min(v,dp[left][right+1][1] + 1);
    }

    if(v==MAX)
        v=0;
    dp[lIndex][rIndex][dir] = v;
    return v;
}

int minTurnToMakeAllColorSame(int* arr){
    clearDP();
    int mini=MAX;
    for(int i=0;i<n;i++){
        int v = minTurn(arr,i,i,0);
        mini=min(mini,v);
    }
    return mini;
}

int main(){
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minTurnToMakeAllColorSame(arr);

    return 0;
}

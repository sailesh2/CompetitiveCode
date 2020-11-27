#include<bits/stdc++.h>

using namespace std;
int n,k,z;
int dp[100005][5][2];

void clearDP(){
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<5;j++){
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
    }
}

int maxPath(int* arr, int index, int ctr, int lefts, int conseqLeft){
    if(index==n)
        return 0;
    int v=arr[index];
    int p;
    if(conseqLeft==0){
        p=dp[index+1][lefts][0]==-1?maxPath(arr,index+1,lefts,0):dp[index+1][lefts][0];
        if(lefts>0)
            p=max(p,dp[index+1][lefts-1][1]==-1?maxPath(arr,index+1,lefts-1,1):dp[index+1][lefts-1][1]);
    }else{
        p=dp[index+1][lefts][0]==-1?maxPath(arr,index+1,lefts,0):dp[index+1][lefts][0];
    }

    dp[index][lefts][conseqLeft]=p+v;
    return p+v;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k>>z;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }

        clearDP();
        cout<<maxPath(arr,0,z,0)<<"\n";
    }
    return 0;
}

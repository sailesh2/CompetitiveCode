#include<bits/stdc++.h>

using namespace std;

int n;

int dp[200005][2];

void clearDP(){
    for(int i=0;i<=n+1;i++){
        dp[i][0]=-2;
        dp[i][1]=-2;
    }
}

int minSteps(int index, int status, int* arr, int* has){
    if(has[index]==1)
        return -1;
    if(arr[index]%2==status)
        return 0;
    int v=-1;
    has[index]=1;
    if(index-arr[index]>=0){
        if(dp[index-arr[index]][status]<0)
            v=minSteps(index-arr[index],status,arr,has);
        else
            v=dp[index-arr[index]][status];
        if(v!=-1)
            v++;
    }

    if(index+arr[index]<n){
        int v1;
        if(dp[index+arr[index]][status]<0)
            v1=minSteps(index+arr[index],status,arr,has);
        else
            v1=dp[index+arr[index]][status];
        if(v1!=-1)
            v1++;
        if(v==-1){
            v=v1;
        }else if(v1!=-1){
            v=min(v,v1);
        }
    }
    has[index]=0;
    dp[index][status]=v;
    return v;
}

int main(){
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    clearDP();
    for(int i=0;i<n;i++){
        if(dp[i][1-(arr[i]%2)]<0){
            int has[200005]={0};
            //has[i]=1;
            cout<<minSteps(i,1-(arr[i]%2),arr,has)<<" ";
            //has[i]=0;
        }
        else
        cout<<dp[i][1-(arr[i]%2)]<<" ";
    }
    return 0;
}

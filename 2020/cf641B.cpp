#include<bits/stdc++.h>

using namespace std;

int dp[100005];

void clearDP(int n){
    for(int i=0;i<=n+1;i++)
        dp[i]=-1;
}

int start(int index, int n, int* arr){
    if(index>n)
        return 0;

    int c=1;
    int maxi=0;
    for(int i=2*index;i<=n;i=i+index){

        if(arr[index]<arr[i]){
            if(dp[i]==-1)
                maxi=max(maxi,start(i,n,arr));
            else
                maxi=max(maxi,dp[i]);
        }
    }
    dp[index]=maxi+c;
    return maxi+c;
}

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int arr[n+1];
        for(int j=0;j<n;j++){
            cin>>arr[j+1];
        }
        clearDP(n);
        int maxi=0;
        for(int j=1;j<=n;j++){
            if(dp[j]==-1)
                maxi=max(maxi,start(j,n,arr));
            else
                maxi=max(maxi,dp[j]);
        }
        cout<<maxi<<"\n";
    }
    return 0;
}

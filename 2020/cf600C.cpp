#include<bits/stdc++.h>

using namespace std;
long long int dp[200005];
long long int m;
long long int calDP(long long int ind, long long int *arr){
    if(ind<0)
        return 0LL;
    long long int s=0;
    if(ind-m>=0){
        if(dp[ind-m]==-1){
            s=calDP(ind-m,arr);
        }else{
            s=dp[ind-m];
        }
    }
    s=s+arr[ind];
    dp[ind]=s;
    return s;
}

int main(){
    long long int n;
    cin>>n>>m;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        dp[i]=-1;
    }
    sort(arr,arr+n);
    long long int s=0;
    long long int ctr=0;
    long long int ans=0;
    long long int d=1;
    for(long long int i=n-1;i>=0;i--){
        s=s+arr[i];
        ctr++;
        if(ctr==m){
            ctr=0;
            ans=ans+s*d;
            d++;
            s=0;
        }
    }

    if(ctr>0){
        ans=ans+s*d;
    }
    for(long long i=n-1;i>=0;i--){
        calDP(i,arr);
    }
    long long int daysAns[n];
    for(long long int i=n-1;i>=0;i--){
        daysAns[i]=ans;
        ans=ans-dp[i];
    }
    for(long long int i=0;i<n;i++){
        cout<<daysAns[i]<<" ";
    }
    return 0;
}

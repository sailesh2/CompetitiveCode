#include<bits/stdc++.h>

using namespace std;

long long int costGreatFence(long long int start, pair<long long int,long long int>* arr, long long int* dp, long long int n, long long int prev){

    if(start>=n-1)
        return 0LL;

    long long int val;
    if(start==n-2){
        pair<long long int,long long int> f=arr[start];
        pair<long long int,long long int> s=arr[start+1];

        if(f.first==s.first){
            val=min(f.second+prev,s.second);
        }
        else{
            val=0LL;
        }
    }else{

        pair<long long int,long long int> f=arr[start];
        pair<long long int,long long int> s=arr[start+1];
        pair<long long int,long long int> t=arr[start+2];

        if(f.first==s.first){
            val=f.second + (dp[start+1]==-1?costGreatFence(start+1,arr,dp,n):dp[start+1]);
            val=min(val, s.second*(s.first+1==t.first?2:1) + (dp[start+2]==-1?costGreatFence(start+2,arr,dp,n):dp[start+2]));
        }else{
            val=dp[start+1]==-1?costGreatFence(start+1,arr,dp,n):dp[start+1];
        }
    }

    dp[start]=val;
    return val;
}

int main(){
    long long int q;
    cin>>q;
    long long int n;
    long long int a,b;
    for(long long int i=0;i<q;i++){
        cin>>n;
        pair<long long int,long long int> arr[n];
        long long int dp[n];
        for(long long int j=0;j<n;j++){
            dp[j]=-1;
            cin>>a>>b;
            arr[j]=make_pair(a,b);
        }
        cout<<costGreatFence(0,arr,dp,n)<<"\n";
    }
    return 0;
}

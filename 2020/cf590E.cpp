#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    long long int arr[m];
    long long int cuml[n+1];
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=n;i++)
        cuml[i]=0;
    long long int s=0;
    vector<long long int> adj[n+1];

    for(int i=1;i<m;i++){
        s=s+abs(arr[i]-arr[i-1]);
        if(arr[i]!=arr[i-1]){
            cuml[1+min(arr[i],arr[i-1])]++;
            cuml[max(arr[i],arr[i-1])]--;

            adj[arr[i]].push_back(arr[i-1]);

            adj[arr[i-1]].push_back(arr[i]);
        }
    }

    for(int i=1;i<=n;i++){
        cuml[i]=cuml[i]+cuml[i-1];
    }

    for(int i=1;i<=n;i++){
        long long int ans=s-cuml[i];
        for(int j=0;j<adj[i].size();j++){
            if(adj[i][j]<i){
                ans=ans-(i-adj[i][j]);
                ans=ans+adj[i][j];
            }else{
                ans=ans-(adj[i][j]-i);
                ans=ans+adj[i][j]-1;
            }
        }
        cout<<ans<<" ";
    }
    return 0;
}

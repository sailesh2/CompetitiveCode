#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int x[k];
    for(int i=0;i<k;i++){
        cin>>x[i];
    }

    int has[100005]={0};
    int pos[100005]={0};
    int dp[100005]={0};

    for(int i=0;i<k;i++){
        if(has[x[i]]==0){
            pos[i]=1;
            has[x[i]]=1;
        }
    }
    int ctr=0;
    for(int i=k-1;i>=0;i--){
        int val=x[i];

        if(pos[i]==1){
            if(val-1>0){
                if(dp[val-1]==0)
                    ctr++;
            }
            if(val+1<=n){
                if(dp[val+1]==0)
                    ctr++;
            }
        }
        dp[val]=1;
    }

    for(int i=1;i<=n;i++){
        if(has[i]==0){
            ctr++;
            if(i-1>0){
                ctr++;
            }
            if(i+1<=n){
                ctr++;
            }
        }
    }
    cout<<ctr;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

long long int dp[105][105];

void clearDp(){
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            dp[i][j]=-1;
        }
    }
}

long long int findMinCutCost(long long int x,long long int y, int start,int endi,vector<int> wood){
    if(start>=endi)
        return 0;
    long long int mini=0,left,right;
    int cnt=0;
    for(int i=start+1;i<endi;i++){
        if(dp[start][i]!=-1){
            left=dp[start][i];
        }else{
            left=findMinCutCost(x,y,start,i,wood);
        }

        if(dp[i][endi]!=-1){
            right=dp[i][endi];
        }else{
            right=findMinCutCost(x,y,i,endi,wood);
        }

        left=left+(wood[i]-wood[start])*x;
        right=right+(wood[endi]-wood[i])*y;
        //cout<<left<<" "<<right<<"\n";
        if(cnt==0){
            mini=left+right;
        }else{
            mini=min(mini,left+right);
        }
        cnt=1;
    }
    dp[start][endi]=mini;
    return mini;
}

int main(){
    int t,n,w;
    long long int x,y;
    cin>>t;
    vector<int> wood;
    long long int ans[t];
    for(int i=0;i<t;i++){
        cin>>x>>y;
        cin>>n;
        wood.clear();
        for(int j=0;j<n;j++){
            cin>>w;
            wood.push_back(w);
        }
        clearDp();
        ans[i]=findMinCutCost(x,y,0,wood.size()-1,wood);
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}

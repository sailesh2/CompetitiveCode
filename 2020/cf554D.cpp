#include<bits/stdc++.h>

using namespace std;
pair<int,int> dp[1005][1005];
int n;
int mod=1000000007;

void preProcess(){
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++)
            dp[i][j]=make_pair(-1,-1);
    }
}

int getLeft(pair<int,int> pL, pair<int,int> pR, int cntL, int cntR){
    if(cntL==0 && cntR==0)
        return 0;
    else if(cntL==0 && cntR==1)
        return (pR.second+1)%mod;
    else if(cntL==1 && cntR==0)
        return (pL.second+1)%mod;
    else
        return (max( (pL.second+pR.second)%mod, max( (pL.first+pR.second)%mod, (pL.second+pR.first)%mod))+1)%mod;
}

int getRight(pair<int,int> pL, pair<int,int> pR){
    int p1=(pL.second+pR.second)%mod;
    int p2=max((pL.first+pR.second)%mod,(pL.second+pR.first)%mod);
    int p3=(pL.first+pR.first)%mod;
    return max(p1,max(p2,p3));
}

pair<int,int> maxMatchingTries(int left, int right){

    pair<int,int> pL = make_pair(0,0);
    pair<int,int> pR = make_pair(0,0);

    if(left==n && right==n)
        return pL;

    int cntR=0;
    if(right<left){
        cntR=1;
        if(dp[left][right+1]==make_pair(-1,-1))
            pR=maxMatchingTries(left,right+1);
        else
            pR=dp[left][right+1];
    }

    int cntL=0;
    if(left<n){
        cntL=1;
        if(dp[left+1][right]==make_pair(-1,-1))
            pL=maxMatchingTries(left+1,right);
        else
            pL=dp[left+1][right];
    }

    pair<int,int> ans = make_pair(getLeft(pL,pR,cntL,cntR),getRight(pL,pR));
    dp[left][right]=ans;
    return ans;
}

int main(){
    cin>>n;
    preProcess();
    pair<int,int> a = maxMatchingTries(1,0);
    cout<<max(a.first,a.second);
    return 0;
}

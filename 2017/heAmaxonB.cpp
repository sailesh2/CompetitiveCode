#include<bits/stdc++.h>

using namespace std;

long long int dp[3][100005];

void clearDP(){
    for(int i=0;i<3;i++){
        for(int j=0;j<100005;j++){
            dp[i][j]=-1;
        }
    }
}

long long int findMinCost(int ind, int ban,vector<int> a, vector<int> b, vector<int> c){
    if(ind==a.size()){
        return 0;
    }

    long long int mini,cost1,cost2,cost3;
    if(ind==0){
        if(dp[0][ind+1]!=-1){
            cost1=dp[0][ind+1];
        }else{
            cost1=findMinCost(ind+1,0,a,b,c);
        }
        cost1=cost1+a[ind];

        if(dp[1][ind+1]!=-1){
            cost2=dp[1][ind+1];
        }else{
            cost2=findMinCost(ind+1,1,a,b,c);
        }
        cost2=cost2+b[ind];

        if(dp[2][ind+1]!=-1){
            cost3=dp[2][ind+1];
        }else{
            cost3=findMinCost(ind+1,2,a,b,c);
        }
        cost3=cost3+c[ind];

    }else{

        if(ban==0){
            if(dp[1][ind+1]!=-1){
                cost1=dp[1][ind+1];
            }else{
                cost1=findMinCost(ind+1,1,a,b,c);
            }
            cost1=cost1+b[ind];

            if(dp[2][ind+1]!=-1){
                cost2=dp[2][ind+1];
            }else{
                cost2=findMinCost(ind+1,2,a,b,c);
            }
            cost2=cost2+c[ind];

        } else if(ban==1){
            if(dp[0][ind+1]!=-1){
                cost1=dp[0][ind+1];
            }else{
                cost1=findMinCost(ind+1,0,a,b,c);
            }
            cost1=cost1+a[ind];

            if(dp[2][ind+1]!=-1){
                cost2=dp[2][ind+1];
            }else{
                cost2=findMinCost(ind+1,2,a,b,c);
            }
            cost2=cost2+c[ind];
        } else{
            if(dp[0][ind+1]!=-1){
                cost1=dp[0][ind+1];
            }else{
                cost1=findMinCost(ind+1,0,a,b,c);
            }
            cost1=cost1+a[ind];

            if(dp[1][ind+1]!=-1){
                cost2=dp[1][ind+1];
            }else{
                cost2=findMinCost(ind+1,1,a,b,c);
            }
            cost2=cost2+b[ind];
        }
    }
    if(ind==0){
        dp[ban][ind]=min(min(cost1,cost2),cost3);
        return min(min(cost1,cost2),cost3);
    }else{
        dp[ban][ind]=min(cost1,cost2);
        return min(cost1,cost2);
    }
}

int main(){
    int t,n,a,b,c;
    cin>>t;
    vector<int> arr;
    vector<int> brr;
    vector<int> crr;
    long long int ans[t];
    for(int i=0;i<t;i++){
        cin>>n;
        arr.clear();
        brr.clear();
        crr.clear();
        for(int j=0;j<n;j++){
            cin>>a>>b>>c;
            arr.push_back(a);
            brr.push_back(b);
            crr.push_back(c);
        }
        clearDP();
        ans[i]=findMinCost(0,0,arr,brr,crr);
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> mat;
int dp[205][1005];
int MAX=1000000007;
void clearDP(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<1005;j++)
            dp[i][j]=-1;
    }
}

int minOR(int index, int prev){
    if(index==n)
        return prev;
    int c=MAX;
    for(int i=0;i<m;i++){

        c=min(c,((dp[index+1][prev|mat[index][i]]==-1)?minOR(index+1,prev|mat[index][i]):dp[index+1][prev|mat[index][i]]));
    }

    dp[index][prev]=c;
    return c;
}

int main(){
    cin>>n>>m;
    int arr[n],brr[m];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<m;i++)
        cin>>brr[i];

    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<m;j++){
            v.push_back(arr[i]&brr[j]);
        }
        mat.push_back(v);
    }

    clearDP();

    cout<<minOR(0,0);
    return 0;
}

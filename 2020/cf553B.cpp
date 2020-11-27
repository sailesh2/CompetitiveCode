#include<bits/stdc++.h>

using namespace std;
int n,m;
int dp[505][1025];
int arr[505][505];
vector<int> ans;

void preProcess(){
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<1025;j++){
            dp[i][j]=-1;
        }
    }
}

bool xorPossible(int row, int x, vector<int> pos){
    if(row==n){
        if(x>0){
            ans=pos;
            return true;
        }
        return false;
    }
    for(int i=0;i<m;i++){
            if(dp[row+1][x^arr[row][i]]==-1){
                pos.push_back(i);
                if(xorPossible(row+1,x^arr[row][i],pos)){
                    dp[row][x]=0;
                    return true;
                }
                pos.pop_back();
            }else{
                if(dp[row+1][x^arr[row][i]]==0){
                    dp[row][x]=0;
                    return true;
                }
            }

    }
    dp[row][x]=1;
    return false;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    preProcess();
    vector<int> pos;
    if(xorPossible(0,0,pos)){
        cout<<"TAK\n";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]+1<<" ";
        }
    }else{
        cout<<"NIE";
    }
    return 0;
}

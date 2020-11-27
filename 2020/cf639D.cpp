#include<bits/stdc++.h>

using namespace std;
int n,m;
int connInd[1001][1001];
int maxConnectCtr=0;
int height[1000001]={0};
int parent[1000001]={0};

int getIndex(int x){
    while(parent[x]!=0){
        x=parent[x];
    }

    return x;
}

int getIndex(int x, int y){
    x=getIndex(x);
    y=getIndex(y);

    if(x==y)
        return x;
    else{

        if(height[x]>height[y]){
            parent[y]=x;
            height[y]++;
            return x;
        }else{
            parent[x]=y;
            height[x]++;
            return y;
        }
    }
}

bool possible(string* grid){
    bool allWhiteRow=false,allWhiteCol=false;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            if(grid[i][j]=='#'){
                if(cnt==2){
                    return false;
                }else{
                    cnt=1;
                }
            }else{
                if(cnt==1)
                    cnt=2;
            }
        }
        if(cnt==0)
            allWhiteRow=true;
    }

    for(int i=0;i<m;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(grid[j][i]=='#'){
                if(cnt==2){
                    return false;
                }else{
                    cnt=1;
                }
            }else{
                if(cnt==1)
                    cnt=2;
            }
        }
        if(cnt==0)
            allWhiteCol=true;
    }

    return (allWhiteCol&&allWhiteRow) || (!allWhiteCol&&!allWhiteRow);
}

int connected(string* grid){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='#'){
                if(i-1>=0 && grid[i-1][j]=='#' && j-1>=0 && grid[i][j-1]=='#'){
                    connInd[i][j]=getIndex(connInd[i-1][j],connInd[i][j-1]);
                }else if(i-1>=0 && grid[i-1][j]=='#'){
                    connInd[i][j]=connInd[i-1][j];
                }else if(j-1>=0 && grid[i][j-1]=='#'){
                    connInd[i][j]=connInd[i][j-1];
                }else{
                    connInd[i][j]=++maxConnectCtr;
                }
            }
        }
    }

    set<int> st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='#'){
                st.insert(getIndex(connInd[i][j]));
            }
        }
    }

    return st.size();
}

int main(){
    cin>>n>>m;
    string grid[n];
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }

    if(possible(grid)){
        cout<<connected(grid);
    }else{
        cout<<"-1";
    }
    return 0;
}

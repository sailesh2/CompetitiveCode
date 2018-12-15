#include<bits/stdc++.h>

using namespace std;

int path[500]={0};
int travelled[500]={0};
int marked[500]={0};
int dp[500];
int dpTime[500][1700];

int n,globalMin=1000000000;
int markPath(int ind,vector<int>* veichle){
    int next,minDis=1000000000,dis;
    if(ind == n){
        return 0;
    }
    for(int i=0;i<veichle[ind].size();i++){
        next=veichle[ind][i];
        if(travelled[next]==0){
            travelled[next]=1;
            if(dp[next]!=-1){
                dis=dp[next]+1;
            } else{
                dis=markPath(next,veichle)+1;
            }
            if(dis<minDis){
                marked[ind]=next;
                minDis = dis;
            }
            travelled[next]=0;
        }
    }
    dp[ind]=minDis;
    return minDis;
}

int findShort(int ind,vector<int>* veichle, int t){
    int next,minDis=1000000000,dis;
    if(ind == n){
        return 0;
    }
    if(t == path[ind]){
        return minDis;
    }
    for(int i=0;i<veichle[ind].size();i++){
        next=veichle[ind][i];
        if(travelled[next]==0){
            travelled[next]=1;
            if(dpTime[next][t+1]!=-1){
                dis=dpTime[next][t+1]+1;
            } else{
                dis=findShort(next,veichle,t+1)+1;
            }

            if(dis<minDis){
                minDis = dis;
            }

            travelled[next]=0;
        }
    }
    dpTime[ind][t]=minDis;
    return minDis;
}

void traverse(int ind, int time){
    if(ind==n || ind<0)
        return;
    path[ind]=time;
    traverse(marked[ind],time+1);
}

void clearPath(){
    for(int i=0;i<500;i++){
        path[i]=-1;
        marked[i]=-1;
    }
}

void clearTravel(){
    for(int i=0;i<500;i++){
        travelled[i]=0;
        dp[i]=-1;
        for(int j=0;j<1700;j++){
            dpTime[i][j]=-1;
        }
    }
}

int main(){
    int m;
    cin>>n>>m;
    int u,v;
    int has[500][500]={0};
    vector<int> train[n+1];
    vector<int> bus[n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        train[u].push_back(v);
        train[v].push_back(u);
        has[u][v]=1;
        has[v][u]=1;
    }

    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if(i!=j && has[i][j]==0)
            {
                bus[i].push_back(j);
                bus[j].push_back(i);
            }
        }
    }

    clearPath();

    clearTravel();
    travelled[1]=1;
    int minValT = markPath(1,train);

    traverse(1,0);

    clearTravel();
    travelled[1]=1;
    path[0]=-1;
    path[1]=-1;
    int minValB = findShort(1,bus,0);

    int minVal = (minValT == globalMin || minValB == globalMin) ? -1 : max(minValT,minValB);

    clearPath();

    clearTravel();
    travelled[1]=1;
    int minValB2=markPath(1,bus);

    traverse(1,0);

    clearTravel();
    travelled[1]=1;
    path[0]=-1;
    path[1]=-1;
    int minValT2=findShort(1,train,0);

    int minVal2 = (minValT2 == globalMin || minValB2 == globalMin) ? -1 : max(minValT2,minValB2);


    int ans=min(minVal,minVal2);
    if(ans == globalMin){
        ans=-1;
    }
    cout<<ans;
    return 0;
}

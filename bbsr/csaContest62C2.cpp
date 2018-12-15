#include<bits/stdc++.h>

using namespace std;
vector<int> graph[1005];
int has[1005]={0};
int dp[1005];

void clearDP(){
    for(int i=0;i<1005;i++){
        dp[i]=-1;
    }
}

int simplePaths(int ind, int dest){
    int next;
    if(ind==dest){
        dp[ind]=1;
        return 1;
    }
    int c=0;
    for(int i=0;i<graph[ind].size();i++){
        next=graph[ind][i];
        if(dp[next]!=-1){
            c=c+dp[next];
        }else{
            if(has[next]==0){
                has[next]=1;
                c=c+simplePaths(next,dest);
                has[next]=0;
            }
        }
    }
    dp[ind]=c;
    return c;
}
int main(){
    int n,m,q,c;
    cin>>n>>m>>q;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=0;i<q;i++){
        cin>>u>>v;
        clearDP();
        if(u==v){
            cout<<"0\n";
        }else{
        has[u]=1;
        c=simplePaths(u,v);
        has[u]=0;
        if(c==1)
            cout<<c<<"\n";
        else
            cout<<0<<"\n";
        }
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
vector<int> graph[1005];
int has[1005]={0};

void clearHas(){
    for(int i=0;i<1005;i++){
        has[i]=0;
    }
}
int simplePaths(int ind, int par,int dest){
    int next;
    if(ind==dest){
        return 1;
    }
    int c=0,pos=0;
    for(int i=0;i<graph[ind].size();i++){
        next=graph[ind][i];

        if(has[next]==0){
            has[next]=1;
            c=simplePaths(next,ind,dest);
            if(c==-1){
                break;
            }
            if(c==1)
                pos=1;
        } else{
            if(next!=par){
                return -1;
            }
        }

    }
    if(c==-1)
        return -1;
    else
        return pos;
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
        if(u==v)
            cout<<"0\n";
        else{
        clearHas();

        has[u]=1;
        c=simplePaths(u,-1,v);

        if(c==1)
            cout<<c<<"\n";
        else
            cout<<0<<"\n";
        }
    }
    return 0;
}

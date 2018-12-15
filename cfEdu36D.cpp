#include<bits/stdc++.h>

using namespace std;
vector<int> graph[1000];
int has[1000]={0};
int visited[1000]={0};
int has2[1000]={0};
int ban[505][505]={0};
int ctr[505][505]={0};
int found=0,save;
vector<pair<int,int> > path;
bool possible=true;
void cycle(int root){
    int next;
    visited[root]=1;
    for(int i=0;i<graph[root].size();i++){

        next=graph[root][i];
        if(has[next]==0){
            has[next]=1;
            cycle(next);
            has[next]=0;
        }else{
            save=next;
            found=1;
        }

        if(found==1){
            path.push_back(make_pair(root,next));
            if(root==save){
                found=2;
            }
            return;
        }else if(found==2){
            return;
        }
    }

}


void cycleWithoutPath(int root){
    int next;
    for(int i=0;i<graph[root].size();i++){
        next=graph[root][i];
        if(ban[root][next]==0 && has2[next]==0){
            has2[next]=1;
            cycleWithoutPath(next);
            has2[next]=0;
            if(!possible)
                return;
        }else{
            if(ban[root][next]==0){
                possible=false;
                return;
            }
        }
    }
}

int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        ctr[u][v]++;
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
        has[i]=1;
        cycle(i);
        has[i]=0;
        }
    }
    if(found==0)
        cout<<"YES";
    else{
        possible=false;
        for(int i=0;i<path.size();i++){
            if(ctr[path[i].first][path[i].second]==1){
                ban[path[i].first][path[i].second]=1;
                possible=true;
                has2[1]=1;
                cycleWithoutPath(1);
                has2[1]=0;
                if(possible)
                    break;
                ban[path[i].first][path[i].second]=0;
            }
        }
        if(possible)
            cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}

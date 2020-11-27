#include<bits/stdc++.h>

using namespace std;
int visited[5005]={0};
int visited1[5005]={0};
int k=1;
map<pair<int,int>,int> colorMp;
map<pair<int,int>,int>::iterator colorMpIt;
map<pair<int,int>,int> dupColorMp;
map<pair<int,int>,int>::iterator dupColorMpIt;

bool isCycleExists(int root, int p, vector<int>* graph, int* has){
    visited1[root]=1;

    for(int i=0;i<graph[root].size();i++){
        int next = graph[root][i];

        if(visited1[next]==0){
            has[next]=1;
            if(isCycleExists(next, root, graph, has))
                return true;
            has[next]=0;
        }else{
            if(has[next]==1){
                return true;
            }
        }
    }

    return false;
}

void colorGraph(int root, int p, vector<int>* graph, int* has, int color){
    visited[root]=1;

    for(int i=0;i<graph[root].size();i++){
        int next = graph[root][i];
        colorMp.insert(make_pair(make_pair(root,next),root>next?1:0));

        if(visited[next]==0){

            has[next]=1;
            colorGraph(next, root, graph, has,1-color);
            has[next]=0;
        }
    }
}

int main(){
    int n,m,u,v;
    cin>>n>>m;
    vector<int> graph[5005];
    int edge[m][2];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        edge[i][0]=u;
        edge[i][1]=v;
        graph[u].push_back(v);
    }

    bool cycleExists = false;
    int has1[5005]={0};
    for(int i=1;i<=n;i++){
        if(visited1[i]==0){
            has1[i]=1;
            if(isCycleExists(i,-1,graph,has1)){
                cycleExists=true;
                break;
            }
            has1[i]=0;
        }
    }

    if(cycleExists){
        int has[5005]={0};
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                has[i]=1;
                colorGraph(i,-1,graph,has,0);
                has[i]=0;
            }
        }

        cout<<"2 \n";
        int v;
        for(int i=0;i<m;i++){

            colorMpIt=colorMp.find(make_pair(edge[i][0],edge[i][1]));
            if(colorMpIt==colorMp.end()){
                colorMpIt=colorMp.find(make_pair(edge[i][1],edge[i][0]));
                if(colorMpIt==colorMp.end()){
                    dupColorMpIt=dupColorMp.find(make_pair(edge[i][0],edge[i][1]));
                    v=dupColorMpIt->second;
                }else{
                    v=1-(colorMpIt->second);
                }
            }else{
                v=colorMpIt->second;
            }
            v++;
            cout<<v<<" ";
        }
    }else{
        cout<<"1 \n";
        for(int i=0;i<m;i++){
            cout<<"1 ";
        }
    }
    return 0;
}

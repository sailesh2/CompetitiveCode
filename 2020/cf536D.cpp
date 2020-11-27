#include<bits/stdc++.h>

using namespace std;
vector<int> finalPath;
set<int> paths;
set<int>::iterator pathsIt;
int has[100005]={0};

void traverseMin(vector<int>* graph){
    pathsIt = paths.begin();
    if(pathsIt == paths.end())
        return;
    int root = *pathsIt;
    has[root]=1;
    finalPath.push_back(root);
    paths.erase(pathsIt);
    for(int i=0;i<graph[root].size();i++){
        if(has[graph[root][i]]==0)
            paths.insert(graph[root][i]);
    }
    traverseMin(graph);
}

int main(){
    int n,m,u,v;
    cin>>n>>m;
    vector<int> graph[n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    paths.insert(1);
    traverseMin(graph);

    for(int i=0;i<finalPath.size();i++){
        cout<<finalPath[i]<<" ";
    }
    return 0;
}

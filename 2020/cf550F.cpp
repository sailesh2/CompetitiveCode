#include<bits/stdc++.h>

using namespace std;

map<pair<int,int>,int> directions;
map<pair<int,int>,int>::iterator directionsIt;


bool assignDirections(vector<int>* tree, vector<int> vertices, int dir){
    vector<int> nextVertices;

    for(int i=0;i<vertices.size();i++){
        int root=vertices[i];
        for(int j=0;j<tree[root].size();j++){
            int child = tree[root][j];
            directionsIt = directions.find(make_pair(root,child));
            if(directionsIt==directions.end()){
                directions.insert(make_pair(make_pair(root,child),dir));
                directions.insert(make_pair(make_pair(child,root),1-dir));
                nextVertices.push_back(child);

            }else if(directionsIt->second != dir){
                return false;
            }
        }
    }
    if(nextVertices.size()==0)
        return true;
    return assignDirections(tree, nextVertices, 1-dir);
}

int main(){
    int n,m;
    cin>>n>>m;
    int u,v;
    vector<int> tree[n+1];
    pair<int,int> edges[m];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        edges[i]= make_pair(u,v);
    }

    vector<int> vertices;
    vertices.push_back(1);
    if(!assignDirections(tree,vertices,0)){
        cout<<"NO";
    }else{
        cout<<"YES\n";
        string dirs="";
        for(int i=0;i<m;i++){
            directionsIt = directions.find(edges[i]);
            dirs.push_back((char)(48+(directionsIt->second)));
        }
        cout<<dirs;
    }
    return 0;
}

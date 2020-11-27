#include<bits/stdc++.h>

using namespace std;
int n,u,v;
vector<int> tree[100005];
map<pair<int,int>,int> edges;
map<pair<int,int>,int>::iterator edgesIt;
int ans[100005]={0};
int ctr=1;

void leaf(int root, int parent){
    int l = tree[root].size();
    if(l==1 && tree[root][0]==parent){
        edgesIt = edges.find(make_pair(parent,root));
        int edgeInd;
        if(edgesIt!=edges.end()){
            edgeInd=edgesIt->second;
        }else{
            edgesIt = edges.find(make_pair(root,parent));
            edgeInd=edgesIt->second;
        }
        ans[edgeInd]=ctr++;
        return;
    }

    for(int i=0;i<l;i++){
        int next = tree[root][i];
        if(parent!=next){
            leaf(next, root);
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        edges.insert(make_pair(make_pair(u,v),i));
    }


    leaf(1,0);
    if(tree[1].size()==1){
        u=1;
        v=tree[1][0];
        edgesIt = edges.find(make_pair(u,v));
        int edgeInd;
        if(edgesIt!=edges.end()){
            edgeInd=edgesIt->second;
        }else{
            edgesIt = edges.find(make_pair(v,u));
            edgeInd=edgesIt->second;
        }
        if(ans[edgeInd]==0)
        ans[edgeInd]=ctr++;
    }
    for(int i=0;i<n-1;i++){
        if(ans[i]==0){
            ans[i]=ctr++;
        }
        cout<<ans[i]-1<<"\n";
    }

    return 0;
}

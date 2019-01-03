#include<bits/stdc++.h>

using namespace std;

vector<long long int> weights;
map<pair<int,int>,long long int> costMap;
map<pair<int,int>,long long int>::iterator costMapIt;
int n;
long long int maxGas=0;

pair<long long int,int> maxGasoline(int root, int parent, vector<int> * tree){
    long long  int w = weights[root];

    vector<long long int> childW;
    for(int i=0;i<tree[root].size();i++){
        int child = tree[root][i];
        pair<long long int,int> ret;
        if(child != parent){
            ret=maxGasoline(child, root, tree);
            costMapIt = costMap.find(make_pair(root,ret.second));
            long long int cost = costMapIt->second;
            if(ret.first - cost>=0)
                childW.push_back(ret.first - cost);
        }
    }

    sort(childW.begin(),childW.end());
    long long int maxchildw = 0;
    if(childW.size()>0)
        maxchildw = childW[childW.size()-1];
    long long int maxchildw2 = 0;
    if(childW.size()>1)
        maxchildw2 = childW[childW.size()-2];

    maxGas = max(maxGas, w+maxchildw+maxchildw2);
    return make_pair(w+maxchildw,root);
}

int main(){
    int u,v;
    long long int w,c;
    cin>>n;
    vector<int> tree[n];
    for(int i=0;i<n;i++){
        cin>>w;
        weights.push_back(w);
    }
    for(int i=0;i<n-1;i++){
        cin>>u>>v>>c;
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
        costMap.insert(make_pair(make_pair(u-1,v-1),c));
        costMap.insert(make_pair(make_pair(v-1,u-1),c));
    }

    maxGasoline(0,-1,tree);
    cout<<maxGas;
    return 0;
}

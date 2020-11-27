#include<bits/stdc++.h>

using namespace std;

long long int pairs=0;

int traverse(int parent, int root, vector<pair<int,int> > *tree, bool possible, int parentOnes){
    int rv=0;
    int totO=0;
    int totZ=0;
    vector<int> zeros;
    vector<int> ones;
    for(int i=0;i<tree[root].size();i++){

        int child=tree[root][i].first;
        if(child!=parent){

            int cost=tree[root][i].second;

            int v = traverse(root,child,tree,cost==1,cost==1?parentOnes+1:0);
            pairs=pairs+(long long int)(v*2);
            if(cost==0){
                zeros.push_back(v);
                totZ=totZ+v;
            }else{
                ones.push_back(v);
                totO=totO+v;
            }
            if(!possible || (possible && cost==1)){
                rv=rv+v;
            }

            if(possible && cost==0){
                pairs=pairs+(long long int)(v*parentOnes);
            }
        }
    }

    for(int i=0;i<zeros.size();i++){
        pairs=pairs+(long long int)(zeros[i]*(totZ-zeros[i]));
    }

    for(int i=0;i<ones.size();i++){
        pairs=pairs+(long long int)(ones[i]*(totO-ones[i]));
    }

    pairs=pairs+(long long int)(zeros.size() * totO);

    rv++;
    return rv;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > tree[n];
    int u,v,c;

    for(int i=0;i<n-1;i++){
        cin>>u>>v>>c;
        tree[u-1].push_back(make_pair(v-1,c));
        tree[v-1].push_back(make_pair(u-1,c));
    }

    int rv = traverse(-1,0,tree,true,0);
    cout<<pairs;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

bool weightComp(pair<int,pair<int,int> > a, pair<int,pair<int,int> > b){
    return a.first>b.first;
}

map<pair<int,int>,int> parentMap;
map<pair<int,int>,int>::iterator parentMapIt;
int n,k;
int MAX=1000000000;
int parentCnt[500005]={0};
int childCnt[500005]={0};
set<int> miniV[500005];
int minK[500005]={0};

void cleanup(){
    for(int i=0;i<=n+1;i++){
        parentCnt[i]=0;
        childCnt[i]=0;
        minK[i]=0;
        miniV[i].clear();
    }
}

void makeTreeRooted(int root, int* has, vector<int>* tree, map<pair<int,int>,int> edgeMap){
    vector<int> v;
    map<pair<int,int>,int>::iterator edgeMapIt;
    for(int i=0;i<tree[root].size();i++){
        int child = tree[root][i];
        if(has[child]==0){
            has[child]=1;
            parentMap.insert(make_pair(make_pair(root,child),root));
            parentMap.insert(make_pair(make_pair(child,root),root));
            edgeMapIt = edgeMap.find(make_pair(root,child));
            v.push_back(edgeMapIt->second);
            makeTreeRooted(child,has,tree,edgeMap);
        }
    }

    if(v.size()>=k){
        minK[root]=v[k-1];
    }else{
        minK[root]=MAX;
    }
}

long long int maxKWeightsAssign(vector<pair<int,pair<int,int> > >& weights){

    long long int sm=0;
    for(int i=0;i<weights.size();i++){
        int w=weights[i].first;
        int u=weights[i].second.first;
        int v=weights[i].second.second;

        parentMapIt = parentMap.find(make_pair(u,v));
        int p = parentMapIt->second;
        int c;
        if(p==u)
            c=v;
        else
            c=u;

        if(childCnt[c]<k){
            if( (parentCnt[p]==0 && childCnt[p]<k) || (parentCnt[p]==1 && childCnt[p]<k-1) ){
                sm=sm+w;
                parentCnt[c]=1;
                childCnt[p]++;
                miniV[p].insert(w-minK[c]);
            }else{
                int val=*(miniV[p].begin());
                if(w>val){
                    sm=sm+w-val;
                    parentCnt[c]=1;
                    miniV[p].erase(miniV[p].begin());
                    miniV[p].insert(w-minK[c]);
                }
            }
        }
    }

    return sm;
}

int main(){
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>n>>k;
        int u,v,w;
        vector<int> tree[n+1];
        map<pair<int,int>,int> edgeMap;
        vector<pair<int,pair<int,int> > > weights;
        for(int j=0;j<n-1;j++){
            cin>>u>>v>>w;
            tree[u].push_back(v);
            tree[v].push_back(u);
            edgeMap.insert(make_pair(make_pair(u,v),w));
            edgeMap.insert(make_pair(make_pair(v,u),w));
            weights.push_back(make_pair(w,make_pair(u,v)));
        }

        sort(weights.begin(),weights.end(),weightComp);

        parentMap.clear();
        int has[n+1]={0};
        has[1]=1;
        makeTreeRooted(1,has,tree, edgeMap);
        cout<<maxKWeightsAssign(weights)<<"\n";
        cleanup();
    }
    return 0;
}

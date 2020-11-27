#include<bits/stdc++.h>

using namespace std;

long long int nodeCost[200005];
long long int subTreeCnt[200005];
long long int ht[200005];
int MAX;


pair<int,long long int> storeSubTreeCost(int root, int* has, vector<int>* tree){

    int cnt=0;
    long long int c=0;
    for(int i=0;i<tree[root].size();i++){
        int child = tree[root][i];
        if(has[child]==0){
            has[child]=1;

            pair<int,long long int> childCost = storeSubTreeCost(child,has,tree);
            c=c+childCost.second;
            cnt=cnt+childCost.first;
        }
    }

    nodeCost[root]=c+cnt+1;
    subTreeCnt[root]=cnt+1;
    return make_pair(cnt+1, c+cnt+1);
}

void calHeight(int root, int* has, vector<int>* tree, int h){
  ht[root]=h;
  for(int i=0;i<tree[root].size();i++){
    int child = tree[root][i];
    if(has[child]==0){
        has[child]=1;
        calHeight(child,has,tree,h+1);
    }
  }
}

long long int htSum(int node, long long int v){
    long long int last = v-ht[node]+1;
    return (v*(v+1))/2 - (last*(last-1))/2;
}

pair<long long int,long long int> points(int root, int* has, vector<int>* tree){
    int cnt=0;
    vector<long long int> childSubCosts;
    long long int s=0;
    vector<int> children;
    for(int i=0;i<tree[root].size();i++){
        int child = tree[root][i];
        if(has[child]==0){
            cnt=1;
            children.push_back(child);
            childSubCosts.push_back(nodeCost[child]);
            s=s+nodeCost[child];
        }
    }

    if(cnt==0){
        return make_pair(MAX,MAX-1);
    }

    long long int maxi=0,save=0,val=0;
    for(int i=0;i<children.size();i++){
        int child = children[i];
            has[child]=1;
            pair<long long int,long long int> p = points(child,has,tree);

            if((p.first + MAX-subTreeCnt[child] + s-childSubCosts[i]) > maxi){
                maxi=p.first + MAX-subTreeCnt[child] + s-childSubCosts[i];
                val=p.first + p.second + s-childSubCosts[i];
                save=MAX-subTreeCnt[root];
            }

    }

    return make_pair(val,save);
}

int main(){
    int n;
    cin>>n;
    MAX=n;
    int u,v;
    vector<int> tree[n+1];
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);

    }
    int has0[200005]={0};
    has0[1]=1;
    calHeight(1,has0,tree,1);

    int has[200005]={0};
    has[1]=1;
    storeSubTreeCost(1,has,tree);
    int has2[200005]={0};
    has2[1]=1;
    cout<<points(1,has2,tree).first;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int parent[300005]={0};
int vals[300005]={0};
int leavesAssigned[300005]={0};
vector<int> leaves;
int v=0;

int getLowestAncestorMax(int parentNode, int* minMax){
    if(parent[parentNode] == 0 || minMax[parent[parentNode]]==0){
        return parentNode;
    }

    return getLowestAncestorMax(parent[parentNode],minMax);
}

void assignAllLeafMax(int root, vector<int>* tree){
    if(tree[root].size()==0){
        if(leavesAssigned[root]==0){
        vals[root]=v;
        leavesAssigned[root]=1;
        }
        return;
    }

    for(int i=0;i<tree[root].size();i++){
        assignAllLeafMax(tree[root][i],tree);
    }
}

void countLeaves(int root, vector<int>* tree){
    if(tree[root].size()==0){
        v++;
        return;
    }
      for(int i=0;i<tree[root].size();i++){
        int child = tree[root][i];
        countLeaves(child,tree);
      }
}

bool traverse(int root, vector<int>* tree, int* minMax, int s){

    if(tree[root].size()==0){

        if(s==0){
            return true;
        }else{
            leaves.push_back(parent[root]);
            return false;
        }
    }
    if(minMax[root]==0){
        s=1;
    }
    for(int i=0;i<tree[root].size();i++){
        int child = tree[root][i];
        if(traverse(child,tree,minMax,s)){
            return true;
        }
    }
    return false;
}

void assignLeaves(vector<int>* tree, int* minMax){
    vector<pair<int,int> > sl;
    int has[200005]={0};
    for(int i=0;i<leaves.size();i++){
        if(has[leaves[i]]==0){
            has[leaves[i]]=1;
            sl.push_back(make_pair(tree[leaves[i]].size(),leaves[i]));
        }

    }

    sort(sl.begin(),sl.end());

    vector<int> slMax;

    for(int i=0;i<sl.size();i++){
        if(minMax[sl[i].second]==0){
            for(int j=0;j<tree[sl[i].second].size();j++){
                int leaf = tree[sl[i].second][j];
                vals[leaf]=v;
                leavesAssigned[leaf]=1;
                v--;
            }
        }else{
            slMax.push_back(sl[i].second);
        }
    }


    for(int i=0;i<slMax.size();i++){
        if(leavesAssigned[slMax[i]]==0){
            assignAllLeafMax(getLowestAncestorMax(slMax[i],minMax),tree);
            v--;
        }
    }
}

int findMinMax(vector<int>* tree, int* minMax,int root){
    if(tree[root].size()==0){
        return vals[root];
    }
    int rv;
    if(minMax[root]==0){
        rv=1000000007;
        for(int i=0;i<tree[root].size();i++){
            int child=tree[root][i];
            rv=min(rv,findMinMax(tree,minMax,child));
        }
    }else{
        rv=0;
        for(int i=0;i<tree[root].size();i++){
            int child=tree[root][i];
            rv=max(rv,findMinMax(tree,minMax,child));
        }
    }
    return rv;
}

int main(){
    int n;
    cin>>n;
    int minMax[n+1];
    vector<int> tree[n+1];
    for(int i=0;i<n;i++){
        cin>>minMax[i+1];
    }
    int p;
    for(int i=0;i<n-1;i++){
        cin>>p;
        tree[p].push_back(i+2);
        parent[i+2]=p;
    }


    countLeaves(1,tree);
    if(traverse(1,tree,minMax,0)){
        cout<<v;
    }else{
        assignLeaves(tree,minMax);
        cout<<findMinMax(tree,minMax,1);
    }
    return 0;
}

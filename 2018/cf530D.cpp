#include<bits/stdc++.h>

using namespace std;
int n;
vector<long long int> val;
vector<long long int> nodeVal;

long long int shouldParentChange(int root, vector<int>* tree, long long int s){
    long long int mini=1000000009;
    if(nodeVal[root]>=0)
        return nodeVal[root];
    for(int i=0;i<tree[root].size();i++){
        if(val[tree[root][i]] !=-1){
            if(val[tree[root][i]]<s)
                return -1;
            mini=min(mini,val[tree[root][i]] - s);
        }
    }
    return mini;
}
long long int restoreTree(int root, int parent, vector<int>* tree, long long int s){
    long long int v=0;
    nodeVal[root]=-1;
    if(val[root]!=-1){
        if(val[root]<s){
            return -1;
        }else if(val[root]>s){
            if(parent != -1){
                long long int earlierP = max(0LL,nodeVal[parent]);
                nodeVal[parent] = shouldParentChange(parent, tree, s);
                if(nodeVal[parent] == -1)
                    return -1;
                s=s+nodeVal[parent] - earlierP;
                nodeVal[root] = val[root] - s;
            }else{
                nodeVal[root] = val[root] - s;
            }
        }else{
            nodeVal[root]=0;
        }
    }

    long long int sumRestored=0,sChild;
    for(int i=0;i<tree[root].size();i++){
        sChild = restoreTree(tree[root][i],root,tree,s+max(0LL,nodeVal[root]));
        if(sChild==-1)
            return -1;
        sumRestored = sumRestored + sChild;
    }
    nodeVal[root] = max(nodeVal[root],0LL);
    return sumRestored + nodeVal[root];
}

int main(){
    int p;
    long long int v;
    cin>>n;
    vector<int> tree[n];
    for(int i=0;i<n-1;i++){
        cin>>p;
        tree[p-1].push_back(i+1);
    }
    for(int i=0;i<n;i++){
        cin>>v;
        val.push_back(v);
        nodeVal.push_back(-1);
    }
    cout<<restoreTree(0,-1,tree,0);
    return 0;
}

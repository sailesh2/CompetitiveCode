#include<bits/stdc++.h>

using namespace std;

int leaves=0;

int maxTree(int root, vector<int>* tree, int* minMax){
    if(tree[root].size()==0){
        leaves++;
        return 1;
    }

    int ans=0;
    if(minMax[root]==1){
        ans=1000000007;
    }
    for(int i=0;i<tree[root].size();i++){
        int v = maxTree(tree[root][i],tree,minMax);
        if(minMax[root]==0){
            ans=ans+v;
        }else{
            ans=min(ans,v);
        }
    }
    return ans;
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
    }

    int leavesValsAssigned = maxTree(1,tree,minMax);
    cout<<leaves+1-leavesValsAssigned;
    return 0;
}

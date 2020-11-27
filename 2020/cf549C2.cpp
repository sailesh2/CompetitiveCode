#include<bits/stdc++.h>

using namespace std;

bool canBeDeleted(int root, vector<int> * tree, int * respect){
    if(respect[root]==0)
        return false;
    for(int i=0;i<tree[root].size();i++){
        if(respect[tree[root][i]]==0)
            return false;
    }
    return true;
}

int main(){
    int n,c,p;
    cin>>n;
    vector<int> tree[n+1];
    int respect[n+1];
    for(int i=0;i<n;i++){
        cin>>p>>c;
        respect[i+1]=c;
        if(p!=-1)
        tree[p].push_back(i+1);
    }
    vector<int> dels;
    for(int i=1;i<=n;i++){
        if(canBeDeleted(i,tree,respect)){
            dels.push_back(i);
        }
    }
    if(dels.size()==0){
        cout<<"-1";
    }else{
    sort(dels.begin(),dels.end());
    for(int i=0;i<dels.size();i++){
        cout<<dels[i]<<" ";
    }
    }
    return 0;
}

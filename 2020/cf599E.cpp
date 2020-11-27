#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,u,v;
    cin>>n>>m;
    vector<int> tree[100005];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        if(u<v){
            tree[u].push_back(v);
        }else{
            tree[v].push_back(u);
        }
    }
    int s=0;
    for(int i=1;i<n;i++){
        sort(tree[i].begin(),tree[i].end());
        if(tree[i].size()==0)
            s=s+n-i;
        for(int j=0;j<tree[i].size();j++){
            if(j==0)
                s=s+tree[i][j]-i-1;
            else
                s=s+tree[i][j]-tree[i][j-1]-1;
        }
        if(s>=n)
            break;
    }
    cout<<max(0,n-s);
    return 0;
}

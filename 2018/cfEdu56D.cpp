#include<bits/stdc++.h>

using namespace std;

long long int connectedComp = 0;
long long int half = 0;

long long int mod=998244353;
//long long int pow2[300005];

long long int pow2(long long int len){
    long long int p=1;
    for(int i=0;i<len;i++){
        p=(p*2)%mod;
    }
    return p;
}

void noOfPossibleVertexNums(int root, int parent, vector<int>* tree, int* has, int * visited, int ctr){
    if(visited[root]!=0){
        return;
    }
    if(has[root]>0){
        if((ctr-has[root])%2!=0){
            connectedComp = -1;
         }
         return;
    }

    connectedComp++;
    has[root]=ctr;
    if(ctr%2==0)
        half++;

    for(int i=0;i<tree[root].size();i++){
        if(tree[root][i]!=parent){
            noOfPossibleVertexNums(tree[root][i], root, tree, has, visited, ctr+1);
        }
        if(connectedComp == -1)
            return;
    }
    visited[root]=1;
    has[root]=0;
}

int main(){
    int t,n,m,u,v;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        vector<int> tree[n];
        for(int j=0;j<m;j++){
            cin>>u>>v;
            tree[u-1].push_back(v-1);
            tree[v-1].push_back(u-1);
        }
        long long int sm=1;
        int has[n];
        int visited[n];
        for(int j=0;j<n;j++){
            has[j]=0;
            visited[j]=0;
        }
        connectedComp = 0;
        half=0;
        for(int j=0;j<n;j++){
            if(visited[j]==0){
                noOfPossibleVertexNums(j,-1,tree,has,visited,1);
                if(connectedComp == -1){
                    sm=0;
                    break;
                }
                if(connectedComp > 0)
                    sm=(sm * ( pow2(connectedComp - half) + pow2(half) )%mod )%mod;
            }
            connectedComp = 0;
            half=0;
        }
        cout<<sm<<"\n";
    }
    return 0;
}

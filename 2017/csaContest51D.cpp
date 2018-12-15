#include<bits/stdc++.h>

using namespace std;
vector<int> tree[100005];
int parent[100005];
int mod=1000000007;
int has[100005]={0};
int has2[100005]={0};
long long int p=1;
int k;

void clearParents(int n){
    for(int i=0;i<n;i++){
        parent[i]=-1;
    }
}

void storeParents(int root){
    int next;
    for(int i=0;i<tree[root].size();i++){
        next=tree[root][i];
        if(has[next]==0){
            has[next]=1;
            parent[next]=root;
            storeParents(next);
        }
    }
}

void findTotalColorCombo(int root,int sibl){
    int next,ctr=0;

    if(parent[root]!=-1){
        ctr++;
        if(parent[parent[root]]!=-1)
            ctr++;
    }
    p=(p*(k-ctr-sibl))%mod;
    int cnt=0;
    for(int i=0;i<tree[root].size();i++){

        next=tree[root][i];
        if(has2[next]==0){
            has2[next]=1;
            findTotalColorCombo(next,cnt);
            cnt++;
        }
    }
}
int main(){
    int n,u,v;
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }
    clearParents(n);
    has[0]=1;
    storeParents(0);
    has2[0]=1;
    findTotalColorCombo(0,0);
    cout<<p;
    return 0;
}

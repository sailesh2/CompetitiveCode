#include<bits/stdc++.h>

using namespace std;

bool comp(long long int a, long long int b){
    return a>b;
}

vector<long long int> tree[200005];
long long int n,k;
vector<long long int> vals;

long long int storeNodeVals(long long int root, long long int* has, long long int h){

    long long int cnt=0;
    for(long long int i=0;i<tree[root].size();i++){
        long long int child = tree[root][i];
        if(has[child]==0){
            has[child]=1;
            cnt=cnt+storeNodeVals(child,has,h+1);
        }
    }

    vals.push_back(h-cnt);
    return cnt+1;
}

int main(){
    long long int u,v;
    cin>>n>>k;
    for(long long int i=0;i<n-1;i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    long long int has[200005]={0};
    has[1]=1;
    storeNodeVals(1,has,0);
    sort(vals.begin(),vals.end(),comp);

    long long int s=0;
    for(long long int i=0;i<k;i++){
        s=s+vals[i];
    }
    cout<<s;
    return 0;
}

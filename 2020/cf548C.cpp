#include<bits/stdc++.h>

using namespace std;

long long int mod = 1000000007;
long long int sumBadTrees = 0;

long long int n,k;

long long int power(long long int base,long long int pow){
    long long int ans=1;
    for(long long int i=0;i<pow;i++){
        ans=(ans*base)%mod;
    }
    return ans;
}

long long int badTrees(long long int root, vector<pair<long long int,long long int> > * trees, long long int* has){
    long long int toReturn = 0;
    long long int bTrees;
    long long int color,next;
    for(long long int i=0;i<trees[root].size();i++){
        next=trees[root][i].first;
        color=trees[root][i].second;

        if(has[next]==0){
            has[next]=1;
            bTrees = badTrees(next,trees,has);
            if(color==1){
     //           cout<<bTrees<<"\n";
                sumBadTrees = (sumBadTrees + power(bTrees,k))%mod;
            }else{
                toReturn = toReturn + bTrees;
            }
            has[next]=0;
        }
    }
    return toReturn+1;
}

int main(){
    cin>>n>>k;
    long long int u,v,c;
    vector<pair<long long int,long long int> > tree[n+1];
    for(long long int i=0;i<n-1;i++){
        cin>>u>>v>>c;
        tree[u].push_back(make_pair(v,c));
        tree[v].push_back(make_pair(u,c));
    }
    long long int has[200005]={0};
    has[1]=1;
    long long int bTrees = badTrees(1LL,tree,has);
    sumBadTrees = (sumBadTrees + power(bTrees,k))%mod;
    has[1]=0;
    long long int gTrees = (power(n,k) - sumBadTrees);
    //cout<<sumBadTrees<<" ";
    if(gTrees<0)
        gTrees = (gTrees+mod)%mod;
    cout<<gTrees;
    return 0;
}

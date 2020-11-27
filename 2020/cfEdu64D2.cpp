#include<bits/stdc++.h>

using namespace std;

long long int pairs=0;

struct DPInfo{
    int val;
    vector<long long int> zeros;
    vector<long long int> ones;
    vector<long long int> oneZeros;
    vector<long long int> zeroOnes;
};

struct DPInfo dp[200005];
long long int dpZeroOnes[200005]={0};
long long int dpOneZeros[200005]={0};;

long long int getSum(vector<long long int> v){
    long long int sm=0;
    for(int i=0;i<v.size();i++){
        sm=sm+v[i];
    }
    return sm;
}

struct DPInfo createDPInfo(int root,vector<pair<int, struct DPInfo> > childDPInfos){
    struct DPInfo nodeInfo;
    nodeInfo.val=root;

    for(int i=0;i<childDPInfos.size();i++){
        int cost=childDPInfos[i].first;
        struct DPInfo childInfo = childDPInfos[i].second;
        if(cost==0){
            nodeInfo.zeros.push_back(getSum(childInfo.zeros)+1);
            nodeInfo.ones.push_back(0);
            nodeInfo.zeroOnes.push_back(0);
            int v=getSum(childInfo.oneZeros)+getSum(childInfo.ones);
            dpOneZeros[root]=dpOneZeros[root]+dpOneZeros[childInfo.val]+getSum(childInfo.ones);
            if(v>0)
            nodeInfo.oneZeros.push_back(v+1);
        }
        else{
            nodeInfo.zeros.push_back(0);
            nodeInfo.ones.push_back(getSum(childInfo.ones)+1);
            int v = getSum(childInfo.zeroOnes) + getSum(childInfo.zeros);
            dpZeroOnes[root]=dpZeroOnes[root]+dpZeroOnes[childInfo.val]+getSum(childInfo.zeros);
            if(v>0)
            nodeInfo.zeroOnes.push_back(v+1);
            nodeInfo.oneZeros.push_back(0);
        }
    }

    return nodeInfo;
}


struct DPInfo storeDP(int parent, int root, vector<pair<int,int> > *tree){
    vector<pair<int,struct DPInfo> > childDPInfos;

    for(int i=0;i<tree[root].size();i++){

        int child=tree[root][i].first;
        if(child!=parent){
            int cost=tree[root][i].second;

            struct DPInfo childDPInfo = storeDP(root,child,tree);
            childDPInfos.push_back(make_pair(cost,childDPInfo));
        }
    }

    struct DPInfo nodeDPInfo = createDPInfo(root,childDPInfos);
    dp[root] = nodeDPInfo;
    return nodeDPInfo;
}

long long int getSamePairs(vector<long long int> v){
    long long int sm=getSum(v);
    long long int p=0;
    for(int i=0;i<v.size();i++){
        p=p+(sm-v[i])*v[i];
    }
    return p + sm*2;
}

long long int getDiffPairs(vector<long long int> v1, long long int v2){
    return getSum(v1)*v2;
}

void calculatePairs(int parent, int root, vector<pair<int,int> > *tree){

    for(int i=0;i<tree[root].size();i++){

        int child=tree[root][i].first;
        if(child!=parent){
            calculatePairs(root,child,tree);
        }
    }

    struct DPInfo nodeInfo = dp[root];
    pairs = pairs + (long long int)(getSamePairs(nodeInfo.zeros));
    pairs = pairs + (long long int)(getSamePairs(nodeInfo.ones));
    pairs = pairs + (long long int)(getDiffPairs(nodeInfo.ones,dpZeroOnes[root]));
    pairs = pairs + (long long int)(getDiffPairs(nodeInfo.zeros,dpOneZeros[root]));
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > tree[n];
    int u,v,c;

    for(int i=0;i<n-1;i++){
        cin>>u>>v>>c;
        tree[u-1].push_back(make_pair(v-1,c));
        tree[v-1].push_back(make_pair(u-1,c));
    }

    storeDP(-1,0,tree);
    calculatePairs(-1,0,tree);
    cout<<pairs;
    return 0;
}

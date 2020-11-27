#include<bits/stdc++.h>

using namespace std;

pair<long long int,long long int> dp[300005];
long long int dpCuml[300005];
long long int dpMin[300005];
long long int mod=1000000007;
long long int MAX_CONSTANT=1000000000007;
void clearDP(int n){
    for(int i=0;i<=n;i++){
        dp[i]=make_pair(-1,-1);
    }
}

bool toysSort(pair<long long int,long long int> a, pair<long long int,long long int> b){
    if(a.second==b.second)
        return a.first>b.first;
    return a.second<b.second;
}

int binSear(vector<pair<long long int,long long int> > toys, int index){

    int cost = toys[index].first;
    int k=toys.size();
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<k && toys[save+ctr].second<cost){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    if(save==-1)
        return k;
    return save+1;
}

int getUpToIndex(vector<pair<long long int,long long int> >& toys,int index){
    return binSear(toys, index);
}

int getNextIndex(vector<pair<long long int,long long int> >& toys,int index){
    return binSear(toys, index);
}

pair<long long int,long long int> minSpaceNestedToys(vector<pair<long long int,long long int> >& toys,int index){
    if(index==toys.size()){
        dpCuml[index]=1;
        dpMin[index]=MAX_CONSTANT;
        return make_pair(0,0);
    }

    minSpaceNestedToys(toys,index+1);

    int upToIndex = getUpToIndex(toys, index);
    int nextIndex = upToIndex;
    if(nextIndex<toys.size()){
        dpCuml[index] = ((dp[nextIndex].second + dpCuml[index+1] - dpCuml[nextIndex])%mod);
        dpMin[index] = min( (toys[index].second - toys[index].first + dp[nextIndex].first)%mod , dpMin[index+1]);

        dp[index]=make_pair( (toys[index].second - toys[index].first + dp[nextIndex].first)%mod,
                            (dp[nextIndex].second + dpCuml[index+1] - dpCuml[nextIndex])%mod);
    }else{
        dpCuml[index] = dpCuml[index+1];
        dpMin[index] = min(toys[index].second , dpMin[index+1]);

        dp[index]=make_pair(toys[index].second,dpCuml[index+1]);
    }
    return  dp[index];
}

int main(){
    int n;
    cin>>n;
    long long int out,in;
    vector<pair<long long int,long long int> > toys;
    for(int i=0;i<n;i++){
        cin>>out>>in;
        toys.push_back(make_pair(out,in));
    }

    sort(toys.begin(),toys.end(),toysSort);
    clearDP(toys.size());

    long long int sm=minSpaceNestedToys(toys,0).second;
    cout<<sm%mod;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
int n,l;
long long int s;
vector<int> tree[100005];
long long int weights[100005];
int maxParts = 0;

int findMaxUpDist(pair<int,long long int> part, vector<long long int>& ancestorWts){
    int ctr=1;
    int save=-1;
    int save2=-1;
    int k=ancestorWts.size();
    while(1){
        while(save+ctr<k && save+ctr+1+part.first<=l && ancestorWts[k-save-ctr-1]+part.second<=s){
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
        return -1;
    return save+ctr;
}

pair<int,long long int> findMaxParts(int root, vector<long long int>& ancestorWts){
    vector<pair<int,long long int> > childCumlParts;
    ancestorWts.push_back(weights[root]);
    for(int i=0;i<tree[root].size();i++){
        childCumlParts.push_back(findMaxParts(tree[root][i],ancestorWts));
    }
    pair<int,int> partReturn;
    if(childCumlParts.size()==0){
        partReturn = make_pair(1,weights[root]);
        ancestorWts.pop_back();
        return partReturn;
    }else{
        maxParts = maxParts + childCumlParts.size() - 1;
        int dist,maxDist=-1,save=-1;
        for(int i=0;i<childCumlParts.size();i++){
            dist = findMaxUpDist(childCumlParts[i],ancestorWts);
            if(dist>maxDist){
                maxDist=dist;
                save=i;
            }
        }
    //    cout<<root<<" -- "<<save<<"\n";
        if(save==-1){
            maxParts++;
            partReturn = make_pair(1,weights[root]);
            ancestorWts.pop_back();
            return partReturn;
        }else{
            partReturn = make_pair(childCumlParts[save].first+1,childCumlParts[save].second+weights[root]);
            ancestorWts.pop_back();
            return partReturn;
        }
    }
}
int main(){
    cin>>n>>l>>s;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>weights[i];
        if(weights[i]>s){
            cnt=-1;
        }
    }
    int p;
    for(int i=0;i<n-1;i++){
        cin>>p;
        tree[p-1].push_back(i+1);
    }
    if(cnt==-1){
        cout<<cnt;
    }else{
        vector<long long int> anc;
        findMaxParts(0,anc);
        if(maxParts>=0)
            cout<<maxParts+1;
        else
            cout<<"-1";
    }
    return 0;
}

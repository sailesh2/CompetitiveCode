#include<bits/stdc++.h>
#define gc getchar

using namespace std;
int dp[2005];
int sumDp[2005];
int k;

inline int lscan()
{
int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

bool offerComp(pair<int,int> offerA, pair<int,int> offerB){
    if(offerA.first==offerB.first)
        return offerA.second>offerB.second;
    return offerA.first<offerB.first;
}

void preProcess(int* shovels){
    for(int i=0;i<=k+1;i++)
        dp[i]=-1;

    int s=0;
    for(int i=0;i<k;i++){
        s=s+shovels[i];
        sumDp[i]=s;
    }
}

int sum(int i, int j){
    if(j<0)
        return sumDp[i];
    return sumDp[i]-sumDp[j];
}

int cost(int index, int* shovels, vector<pair<int,int> > offers){
//cout<<index<<"\n";
    if(index<0)
        return 0;
    int mini=sum(index,-1);
    for(int i=index;i>=0;i--){
        for(int j=0;j<offers.size();j++){
            if(offers[j].first<=index+1){
                if(index-offers[j].first >=0 && dp[index-offers[j].first]!=-1)
                    mini=min(mini,dp[index-offers[j].first] + sum(index,index-offers[j].first+offers[j].second));
                else
                    mini=min(mini,cost(index-offers[j].first,shovels,offers) + sum(index,index-offers[j].first+offers[j].second));

            }
        }
    }

    dp[index]=mini;
    return dp[index];
}

int main(){
    int n,m,o,b;
    n=lscan();
    m=lscan();
    k=lscan();
    int arr[n];
    pair<int,int> brr[m];
    for(int i=0;i<n;i++){
        arr[i]=lscan();
    }
    for(int i=0;i<m;i++){
        b=lscan();
        o=lscan();
        brr[i]=make_pair(b,o);
    }

    sort(arr,arr+n);

    int shovels[k];
    for(int i=0;i<k;i++){
        shovels[i]=arr[i];
    }

    sort(brr,brr+m,offerComp);

    vector<pair<int,int> > offers;
    set<int> taken;
    for(int i=0;i<m;i++){
        if(brr[i].first<=k){
            if(taken.count(brr[i].first)==0){
                offers.push_back(brr[i]);
                taken.insert(brr[i].first);
            }
        }
    }

    preProcess(shovels);
    cout<<cost(k-1,shovels,offers);

    return 0;
}

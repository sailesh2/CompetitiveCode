#include<bits/stdc++.h>

using namespace std;
int mod=1000000007;
vector<pair<int,int> > num;
long long int pow2[100005];
int countComPrime[100]={0};

map<pair<int,int>,long long int> dp;
map<pair<int,int>,long long int>::iterator dpIt;
long long int productSubset(int ind,int bitmask){
    int nbitmask;
    long long int c=0;
    long long int cnt;
    if(ind==num.size()){
        if(bitmask==0)
            return 1;
        else
            return 0;
    }
    nbitmask=bitmask^num[ind].second;
    cnt=pow2[countComPrime[num[ind].first]-1];

    dpIt=dp.find(make_pair(ind+1,nbitmask));
    if(dpIt==dp.end())
    c=(c+(cnt*productSubset(ind+1,nbitmask))%mod)%mod;
    else
    c=(c+(cnt*dpIt->second)%mod)%mod;

    dpIt=dp.find(make_pair(ind+1,bitmask));
    if(dpIt==dp.end())
    c=(c+(cnt*productSubset(ind+1,bitmask))%mod)%mod;
    else
    c=(c+(cnt*dpIt->second)%mod)%mod;

    dp.insert(make_pair(make_pair(ind,bitmask),c));
    return c;
}
int main(){
    int n,val,x,ctr;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int p[11]={2,3,5,7,11,13,17,19,23,29,31};
    int stored[100]={0};
    for(int i=1;i<=70;i++){
        x=i;
        val=0;
        for(int j=0;j<11;j++){
            ctr=0;
            while(x%p[j]==0){
                x=x/p[j];
                ctr++;
            }
            val=val*2+ctr%2;
        }
        if(x==1){
            stored[i]=val;
        }else{
            stored[i]=-1;
        }
    }

    pow2[0]=1;
    for(int i=1;i<=n;i++){
        pow2[i]=(pow2[i-1]*2)%mod;
    }

    for(int i=0;i<n;i++){
        x=arr[i];
        if(stored[x]!=-1 && countComPrime[x]==0)
            num.push_back(make_pair(x,stored[x]));
        countComPrime[x]++;
    }

    long long int c=productSubset(0,0)-1;
    if(c<0)
        c=c+mod;

    int pcm[8]={37,41,43,47,53,59,61,67};

    for(int i=0;i<8;i++){
        ctr=countComPrime[pcm[i]];
        if(ctr>0)
        c=(c*pow2[ctr-1])%mod;
    }
    cout<<c;
    return 0;
}

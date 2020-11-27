#include<bits/stdc++.h>

using namespace std;

long long int n,mod= 998244353;

long long int fac[300005];

bool compDesc(long long a, long long int b){
    return a>b;
}

bool compDescPair(pair<long long int,long long int> a, pair<long long int,long long int> b){
    if(a.first==b.first)
        return a.second>b.second;
    return a.first>b.first;
}

bool compAscPair(pair<long long int,long long int> a, pair<long long int,long long int> b){
    if(a.first==b.first)
        return a.second<b.second;

    return a.first<b.first;
}

void storeFac(){
    long long int p=1;
    fac[0]=p;
    for(long long int i=1;i<=n;i++){
        p=(p*i)%mod;
        fac[i]=p;
    }
}

long long int calculatePer(long long int* arr){
    sort(arr,arr+n);
    long long int p=1,ctr=1;
    for(long long int i=2;i<n;i++){
        if(arr[i]==arr[i-1]){
            ctr++;
        }else{
            p=(p*fac[ctr])%mod;
            ctr=1;
        }
    }
    p=(p*fac[ctr])%mod;
    return p;
}

long long int calculatePer(vector<pair<long long int,long long int> > v){
    sort(v.begin(),v.end(),compAscPair);
    long long int p=1,ctr=1;
    long long int aVal=v[0].first;
    long long int bVal=v[0].second;
    for(long long int i=2;i<n;i++){
        if(v[i].first==aVal || v[i].second==bVal){
            ctr++;
        }else{
            aVal=v[i].first;
            bVal=v[i].second;
            p=(p*fac[ctr])%mod;

            ctr=1;
        }
    }
    p=(p*fac[ctr])%mod;
    return p;
}

bool isBothSorted(vector<pair<long long int,long long int> > v){

    for(int i=1;i<n;i++){
        if(v[i].second>v[i-1].second)
            return false;
    }

    return true;
}

int main(){
    long long int a,b,minA,minB;
    cin>>n;
    long long int arr[n];
    long long int brr[n];
    vector<pair<long long int,long long int> > v;
    for(long long int i=0;i<n;i++){
        cin>>a>>b;
        if(i==0){
            minA=a;
            minB=b;
        }else{
            minA=min(minA,a);
            minB=min(minA,b);
        }
        arr[i]=a;
        brr[i]=b;
        v.push_back(make_pair(a,b));
    }

    storeFac();

    long long int bPers=calculatePer(brr);
    long long int aPers=calculatePer(arr);
    sort(v.begin(),v.end(),compDescPair);

    long long int abPers=isBothSorted(v)?calculatePer(v):(aPers+bPers);

    long long int start=n;
    long long int ans=0;
    for(long long int i=0;i<n;i++){
        if(v[i].first==minA){
            start=i;
            break;
        }
        if(v[i].second==minB){
            ans=( (ans+fac[n-1])%mod - bPers + mod)%mod;
        }else{
            ans=(ans+fac[n-1])%mod;
        }
    }

    for(;start<n;start++){
        if(v[start].second==minB){
            ans=( (ans+fac[n-1])%mod - abPers + mod)%mod;
        }else{
            ans=( (ans+fac[n-1])%mod - aPers + mod)%mod;
        }
    }
    cout<<ans;
    return 0;
}

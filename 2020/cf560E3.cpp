#include<bits/stdc++.h>

using namespace std;

bool comp(pair<long long int,long long int> a, pair<long long int,long long int> b){
    return a.first<b.first;
}
int main(){
    long long int n;
    cin>>n;
    long long int x;

    long long int mod=998244353;
    pair<long long int,long long int> arr[n];
    long long int a[n];
    for(long long int i=0;i<n;i++){
        cin>>x;
        a[i]=x;
        arr[i]=make_pair((x*((i+1)*(n-i))),i);
    }

    long long int brr[n];
    for(long long int i=0;i<n;i++){
        cin>>brr[i];
    }

    sort(arr,arr+n,comp);
    sort(brr,brr+n);
    long long int crr[n];
    long long int mul[n];
    for(long long int i=0;i<n;i++){
        crr[arr[i].second]=brr[n-1-i];
        mul[i]=((i+1)*(n-i))%mod;
    }

    long long int s=0;

    for(long long int i=0;i<n;i++){
        s=(s+( ((crr[i]*a[i])%mod) *mul[i]) %mod)%mod;
    }
    cout<<s;
    return 0;
}


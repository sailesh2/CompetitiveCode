#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<math.h>

using namespace std;

int main(){
    long long int n,x;
    cin>>n>>x;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long int cnt[10005]={0};
    map<long long int,long long int> mp;
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+cnt[x ^ arr[i]];
        cnt[arr[i]]++;
    }
    cout<<sum;
    return 0;
}

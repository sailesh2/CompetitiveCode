#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

bool fun(int a,int b){
    return a>b;
}

int main(){
    int n;
    cin>>n;
    int arr[n],brr[n];
    long long int sum[n],sa=0,sb=0;
    map<long long int,vector<int> > mp;
    map<long long int,vector<int> >::iterator mapIt;
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    for(int i =0;i<n;i++){
        cin>>brr[i];
    }
    vector<int> v;
    for(int i =0;i<n;i++){
        vector<int> v1;
        sum[i] = arr[i] + brr[i];
        mapIt = mp.find(sum[i]);
        if(mapIt!=mp.end()) {
            v1 = mapIt->second;
            mp.erase(mapIt);
        }
        v1.push_back(i);
        mp.insert(make_pair<long long int,vector<int> >(sum[i],v1));
        sa = sa +arr[i];
        sb = sb +brr[i];
    }
    sort(sum,sum+n,fun);

    long long int sma=0,smb=0;
    vector<int> ans;
    int ctr =0;
    for(int i =0;i<n;i++){

        mapIt = mp.find(sum[i]);
        v = mapIt->second;
        ans.push_back(v.at(0));
        sma = sma +arr[v.at(0)];
        smb = smb +brr[v.at(0)];
        v.erase(v.begin());
        mp.erase(mapIt);
        if(v.size() > 0)
            mp.insert(make_pair(sum[i],v));

        if(2*sma>sa && 2*smb>sb){
            ctr = i+1;
            break;
        }
    }
    cout<<ctr<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans.at(i)+1<<" ";
    }
    return 0;
}

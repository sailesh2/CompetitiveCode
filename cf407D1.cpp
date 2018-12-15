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
    int n,m,cnt=0;
    int ctr;
    long long int p=1;
    cin>>n>>m;
    int u,v;
    map<int,int> mp;
    map<int,int>::iterator mapIt;

    for(int i=0;i<m;i++){
        cin>>u>>v;
        ctr=1;
        mapIt = mp.find(u);
        if(mapIt != mp.end()){
            ctr=mapIt->second;
            ctr++;
            mp.erase(mapIt);
        }
        mp.insert(make_pair(u,ctr));
        if(ctr>=n-1){
            cnt=1;
        }

        ctr=1;
        mapIt = mp.find(v);
        if(mapIt != mp.end()){
            ctr=mapIt->second;
            ctr++;
            mp.erase(mapIt);
        }
        mp.insert(make_pair(u,ctr));
        if(ctr>=n-1){
            cnt=1;
        }
    }
    for(int i=1;i<n-1;i++){

            p=p*i;
    }
    if(cnt==0){
        cout<<"0";
    } else if(n<=2){
        cout<<"1";

    }else{
        cout<<p;
    }
    return 0;
}

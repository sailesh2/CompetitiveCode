#include<bits/stdc++.h>

using namespace std;
map<vector<pair<long long int,long long int> >, long long int> powerMp;
map<vector<pair<long long int,long long int> >, long long int>::iterator powerMpIt;

vector<pair<long long int,long long int> > getPowers(long long int x, long long int k){
    vector<pair<long long int,long long int> > p;
    long long int ctr=0;
    while(x%2==0){
        ctr=(ctr+1)%k;
        x=x/2;
    }
    if(ctr>0)
        p.push_back(make_pair(2,ctr));

    for(long long int i=3;i*i<=x;i=i+2){
        ctr=0;
        while(x%i==0){
            ctr=(ctr+1)%k;
            x=x/i;
        }
        if(ctr>0)
            p.push_back(make_pair(i,ctr));
    }

    if(x>2){
        p.push_back(make_pair(x,1));
    }

    return p;
}

long long int matches(long long int x,long long int k){
    vector<pair<long long int,long long int> > p = getPowers(x,k);
    vector<pair<long long int,long long int> > compp;
    for(long long int i=0;i<p.size();i++){
        long long int rem=(k-(p[i].second)%k)%k;
        if(rem>0)
            compp.push_back(make_pair(p[i].first,rem));
    }

    powerMpIt=powerMp.find(compp);
    long long int s=0;
    if(powerMpIt!=powerMp.end()){
        s=powerMpIt->second;
    }

    powerMpIt=powerMp.find(p);
    long long int v=0;
    if(powerMpIt!=powerMp.end()){
        v=powerMpIt->second;
        powerMp.erase(powerMpIt);
    }
    v++;
    powerMp.insert(make_pair(p,v));

    return s;
}

int main(){
    long long int n,k;
    cin>>n>>k;
    long long int arr[n];
    long long int s=0,x;
    for(long long int i=0;i<n;i++){
        cin>>x;
        s=s+matches(x,k);
    }

    cout<<s;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long long int x;
    cin>>n>>x;
    vector<pair<long long int,long long int> > discounts;
    long long int p,d;
    for(int i=0;i<n;i++){
        cin>>p>>d;
        discounts.push_back(make_pair(p,d));
    }
    long long int smd=0;
    long long int mini=x;
    sort(discounts.begin(),discounts.end());
    for(int i=0;i<discounts.size();i++){
        p=discounts[i].first;
        d=discounts[i].second;
        smd=smd+d;
        mini=min(mini,max(p,x)-smd);
    }
    cout<<mini;
    return 0;
}

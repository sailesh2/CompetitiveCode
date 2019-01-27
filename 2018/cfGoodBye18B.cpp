#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long int x,y,a,b;
    vector<pair<long long int,long long int> > bes;
    vector<pair<long long int,long long int> > clue;
    set<pair<long long int,long long int> > mp;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        bes.push_back(make_pair(x,y));
    }

    for(int i=0;i<n;i++){
        cin>>x>>y;
        clue.push_back(make_pair(x,y));
        mp.insert(make_pair(x,y));
    }
    int cnt;
    long long int tx,ty;
    for(int i=0;i<n;i++){
        x = bes[0].first;
        y = bes[0].second;

        a = clue[i].first;
        b = clue[i].second;
        tx=x+a;
        ty=y+b;
        cnt=0;
        for(int j=1;j<n;j++){
           if(mp.count(make_pair(tx-bes[j].first,ty-bes[j].second))==0){
                cnt=1;
                break;
           }
        }
        if(cnt==0){
            cout<<tx<<" "<<ty;
            break;
        }
    }
    return 0;
}

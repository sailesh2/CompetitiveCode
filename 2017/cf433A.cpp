#include<bits/stdc++.h>

using namespace std;

int main(){
    set<pair<int,int> > s;
    set<pair<int,int> >::iterator sIt;
    s.insert(make_pair(10,2));
    s.insert(make_pair(20,3));
    s.insert(make_pair(10,1));
    sIt=s.begin();
    cout<<sIt->first<<" "<<sIt->second;
    sIt++;
    cout<<sIt->first<<" "<<sIt->second;
    sIt++;
    cout<<sIt->first<<" "<<sIt->second;

    return 0;
}

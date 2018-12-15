#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int x,y;
    map<int,int> xhash;
    map<int,int>::iterator xhashIt;
    map<int,int> yhash;
    map<int,int>::iterator yhashIt;
    map<pair<int,int>,int> has;
    map<pair<int,int>,int>::iterator hasIt;

    cin>>n;
    int ctr;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        xhashIt = xhash.find(x);
        if(xhashIt==xhash.end()){
            xhash.insert(make_pair(x,1));
        } else{
            ctr=xhashIt->second;
            xhash.erase(xhashIt);
            xhash.insert(make_pair(x,ctr+1));
        }

        yhashIt = yhash.find(y);
        if(yhashIt==yhash.end()){
            yhash.insert(make_pair(y,1));
        } else{
            ctr=yhashIt->second;
            yhash.erase(yhashIt);
            yhash.insert(make_pair(y,ctr+1));
        }

        hasIt = has.find(make_pair(x,y));
        if(hasIt==has.end()){
            has.insert(make_pair(make_pair(x,y),1));
        } else{
            ctr=hasIt->second;
            has.erase(hasIt);
            has.insert(make_pair(make_pair(x,y),ctr+1));
        }
    }

    long long int sm=0,val;
    for(xhashIt=xhash.begin();xhashIt!=xhash.end();xhashIt++){
        val=(long long int)xhashIt->second;
        if(val>=2)
            sm=sm+((val*(val-1))/2);
    }
    for(yhashIt=yhash.begin();yhashIt!=yhash.end();yhashIt++){
        val=(long long int)yhashIt->second;
        if(val>=2)
            sm=sm+((val*(val-1))/2);
    }
    for(hasIt=has.begin();hasIt!=has.end();hasIt++){
        val=(long long int)hasIt->second;
        if(val>=2)
            sm=sm-((val*(val-1))/2);
    }

    cout<<sm;
    return 0;
}

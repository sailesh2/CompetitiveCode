#include<bits/stdc++.h>

using namespace std;

bool fun(pair<int,int> a,pair<int,int> b){
    return a.first<=b.first && a.second<=b.second;
}

bool isEqualPair(pair<int,int> a,pair<int,int> b){
    return a.first==b.first && a.second==b.second;
}

int main(){
    int n;
    map<int,set<pair<int,int> > > points;
    map<pair<int,int>,int> has;
    map<int,set<pair<int,int>  > >::iterator pointsIt;


    cin>>n;
    int x,y;

    set<pair<int,int> > v;
    set<pair<int,int> >::iterator vIt;
    pair<int,int> ans[n];
    pair<int,int> ansCheck[n];

    for(int i=0;i<n;i++){
        cin>>x>>y;
        pointsIt=points.find(y-x);
        if(pointsIt==points.end()){
            v.clear();
            v.insert(make_pair(x,y));
            points.insert(make_pair(y-x,v));
        } else{
            v=pointsIt->second;
            v.insert(make_pair(x,y));
            points.erase(pointsIt);
            points.insert(make_pair(y-x,v));
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>x;

        pointsIt=points.find(x);


        if(pointsIt==points.end()){
            cnt=1;
        } else{
            v=pointsIt->second;
            if(v.size()<=0){
                cnt=1;
            } else{
                vIt=v.begin();
                ans[i]=*vIt;
                ansCheck[i]=*vIt;
                has.insert(make_pair(ans[i],i));
                v.erase(vIt);
                points.erase(pointsIt);
                points.insert(make_pair(x,v));
            }
        }

    }

    if(cnt==1){
        cout<<"NO";
    } else{
        sort(ansCheck,ansCheck+n,fun);

        for(int i=0;i<n;i++){
            if(!isEqualPair(ans[i],ansCheck[i])){
                if(ans[i].first>=ansCheck[i].first && ans[i].second>=ansCheck[i].second && ((has.find(ansCheck[i]))->second > i)){
                    cnt=1;
                    break;
                }
            }
        }
        if(cnt==1){
            cout<<"NO";
        }else{
            cout<<"YES\n";
            for(int i=0;i<n;i++){
                cout<<ans[i].first<<" "<<ans[i].second<<"\n";
            }
        }
    }

    return 0;
}

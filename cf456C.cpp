#include<bits/stdc++.h>

using namespace std;
bool fun(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b){
    return a.first>b.first;
}
int main(){
    int n,m;
    cin>>n>>m;
    n++;
    int bounty,increase,damage;
    cin>>bounty>>increase>>damage;
    int enemy[n][4];
    int has[n];
    int save[n][2];
    int maxH,stH,reg,e,t,h;
    for(int i=1;i<n;i++){
        cin>>maxH>>stH>>reg;
        enemy[i][0]=maxH;
        enemy[i][1]=stH;
        enemy[i][2]=reg;
        enemy[i][3]=0;
        has[i]=1;
        save[i][0]=-1;
        save[i][1]=0;
        if(maxH<=damage){
            has[i]=0;
        }
    }
    vector<pair<int,pair<int,int> > > stat;
    for(int i=0;i<m;i++){
        cin>>t>>e>>h;
        stat.push_back(make_pair(t,make_pair(e,h)));
    }
    sort(stat.begin(),stat.end(),fun);
    for(int i=0;i<m;i++){
        t=stat[i].first;
        e=(stat[i].second).first;
        h=(stat[i].second).second;
        if(has[e]==1){
            if(h<=damage){
                save[e][0]=t;
                save[e][1]=h;
            }
        }
    }
    for(int i=1;i<n;i++){
        if(save[i][0]!=-1){
            enemy[i][3]=save[i][0];
            enemy[i][1]=save[i][1];
        }
    }
    int maxB=0;
    vector<int> times;
    int cnt=0,kills=0;
    for(int i=1;i<n;i++){
        if(has[i]==1){
            if(enemy[i][1]<=damage){
                cnt=1;
                kills++;
                times.push_back(enemy[i][3]+(int)ceil((damage-enemy[i][1])/(float)enemy[i][2]));
            }
        }
    }
    //cout<<maxiT<<" "<<kills<<"\n";
    if(cnt==0)
        cout<<"-1";
    else{
        sort(times.begin(),times.end());
        int ctr=0;
        for(int i=0;i<times.size();i++){
            ctr++;
            //cout<<times[i]<<"\n";
            maxB=max(maxB,(times[i]*increase+bounty)*ctr);
        }
        cout<<maxB;
    }
   //     cout<<(miniT*increase+bounty)*kills;
    return 0;
}

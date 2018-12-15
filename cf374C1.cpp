#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>


#define gc getchar

using namespace std;
int n,m,maxt,maxi=0;
vector<pair<int,int> > graph[50005];
int dp[50005]={0};
vector<int> ansF;
map<int,int> has;
map<int,int>::iterator hasIt;
int maxCities(int ind,int time,int cnt,vector<int> ans){
    int maxi=0;
    if(time>maxt){
        return 0;
    }
    if(ind==n-1){
        if(cnt>dp[ind]){
            dp[ind]=cnt;
            ansF=ans;
        }
        return dp[ind];
    }
    for(int i=0;i<graph[ind].size();i++){
        int next=graph[ind][i].first;
        hasIt=has.find(next);
        if(hasIt!=has.end() && time>hasIt->second){
            maxi=max(maxi,dp[next]);
            continue;
        } else{
            has.insert(make_pair(next,time));
            ans.push_back(next);
            maxi=max(maxi,maxCities(next,time+graph[ind][i].second,cnt+1,ans));
            ans.pop_back();
        }
    }
    dp[ind]=maxi;
    return maxi;
}

inline int lscan()
{
int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

int main(){
    cin>>n>>m>>maxt;
    int u,v,t;
    for(int i=0;i<m;i++){
        u=lscan();
        v=lscan();
        t=lscan();
        graph[u-1].push_back(make_pair(v-1,t));
    }
    vector<int> ans;
    ans.push_back(0);

    int maxi=maxCities(0,0,1,ans);
    cout<<maxi<<"\n";
    for(int i=0;i<maxi;i++){
        cout<<ansF[i]+1<<" ";
    }
    return 0;
}

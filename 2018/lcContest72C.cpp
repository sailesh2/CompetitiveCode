#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    map<pair<int,int>,int> dp;
    map<pair<int,int>,int>::iterator dpIt;
    vector<pair<int,int> > graph[100000];
    void createGraph(vector<vector<int> > &flights){
        for(int i=0;i<flights.size();i++){
            graph[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        }
    }
    int cheapestPrice(int src,int dst,int cnt,int paths,int sum){
        if(cnt>paths){
            return -1;
        }
        if(src==dst){
            if(cnt<=paths){
                return 0;
            }
            return -1;
        }
        int mini=1000000000;
        int next,price,v;
        for(int i=0;i<graph[src].size();i++){
            next=graph[src][i].first;
            price=graph[src][i].second;
            dpIt=dp.find(make_pair(next,cnt+1));
            if(dpIt==dp.end())
                v=cheapestPrice(next,dst,cnt+1,paths,sum+price);
            else
                v=dpIt->second;
            if(v!=-1){
                mini=min(mini,v+price);
            }
        }
        dp.insert(make_pair(make_pair(src,cnt),mini));
        return mini;
    }
public:
    int findCheapestPrice(int n, vector<vector<int> >& flights, int src, int dst, int K) {
        createGraph(flights);
        int minC=cheapestPrice(src,dst,0,K+1,0);
        if(minC==1000000000)
            return -1;
        else
            return minC;
    }
};

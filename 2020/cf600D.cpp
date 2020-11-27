#include<bits/stdc++.h>

#define gc getchar

using namespace std;
long long int dsuTree[200005]={0};
long long int maxTree[200005]={0};
long long int minTree[200005]={0};
long long int height[200005]={0};

inline long long int lscan()
{
long long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}
void storeDSU(long long int u, long long int v){
    long long int ctru=0,ctrv=0;
    while(dsuTree[u]!=0){
        u=dsuTree[u];
    }
    ctru=height[u];
    while(dsuTree[v]!=0){
        v=dsuTree[v];
    }
    ctrv=height[v];
    if(u!=v){
        if(ctru<ctrv){
            dsuTree[u]=v;
            maxTree[v]=max(maxTree[v],maxTree[u]);
            minTree[v]=min(minTree[v],minTree[u]);
            height[v]=max(height[v],height[u]+1);
        }else{
            dsuTree[v]=u;
            maxTree[u]=max(maxTree[v],maxTree[u]);
            minTree[u]=min(minTree[v],minTree[u]);
            height[u]=max(height[u],height[v]+1);
        }
    }
}

long long int getParent(long long int u){
    while(dsuTree[u]!=0){
        u=dsuTree[u];
    }
    return u;
}

int main(){
    long long int n,m,u,v;
    n=lscan();
    m=lscan();
    for(long long int i=1;i<=n;i++){
        maxTree[i]=i;
        minTree[i]=i;
    }
    for(long long int i=0;i<m;i++){
        u=lscan();
        v=lscan();
        storeDSU(u,v);
    }
    vector<pair<long long int,long long int> > varr;

    set<long long int> taken;
    for(long long int i=1;i<=n;i++){
        long long int p=getParent(i);
        long long int minP=minTree[p];
        long long int maxP=maxTree[p];
        //cout<<i<<"-"<<p<<"\n";
        if(taken.count(minP)==0){
            taken.insert(minP);
            varr.push_back(make_pair(minP,maxP));
        }
    }

    long long int s=0,ctr=0;
    long long int next=0;
    for(long long int i=0;i<varr.size();i++){
        ctr++;
        next=max(next,varr[i].second);
        if(i==varr.size()-1){
            s=s+ctr-1;
        }else{
            if(next<varr[i+1].first){
                s=s+ctr-1;
                ctr=0;
                next=0;
            }
        }
    }

    cout<<s;
    return 0;
}

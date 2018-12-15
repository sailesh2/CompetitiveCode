#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<math.h>

using namespace std;

long long int p2[200005];
long long int pc2[200005];
int k;

long long int binSear(long long int cost){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<k && pc2[save+ctr]<=cost){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    if(save==-1)
        return -1;
    return p2[save];
}

int main(){
    long long int n;
    int m;
    cin>>n>>m>>k;
    long long int p1[m],pc1[m];

    long long int x,s;
    cin>>x>>s;

    for(int i=0;i<m;i++){
        cin>>p1[i];
    }

    for(int i=0;i<m;i++){
        cin>>pc1[i];
    }

    for(int i=0;i<k;i++){
        cin>>p2[i];
    }

    for(int i=0;i<k;i++){
        cin>>pc2[i];
    }

    long long int minCost=x*n;

    long long int cnt = binSear(s);
    if(cnt>=0)
        minCost = min(minCost,(long long int)((n-cnt)*x));

    for(int i=0;i<m;i++){
        if(p1[i]<x){
            if(s>=pc1[i]){
                cnt = binSear(s-pc1[i]);
                if(cnt>=0)
                    minCost=min(minCost,(long long int)((n-cnt)*p1[i]));
                else
                    minCost=min(minCost,(long long int)(n*p1[i]));
            }
        }
    }
    cout<<minCost;
    return 0;
}

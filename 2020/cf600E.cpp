#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,m,x,s;
    cin>>n>>m;
    long long int taken[100005]={0};
    long long int who[100005]={0};
    long long int who2[100005];
    for(long long int i=0;i<n;i++){
        cin>>x>>s;
        for(long long int j=max(0LL,x-s);j<=min(x+s,m);j++){

            who[j]=max(who[j],x+s);
            if(taken[j]==0)
                who2[j]=x-s;
            else
                who2[j]=min(who2[j],x-s);
            taken[j]=1;
        }
    }
    long long int sm=0;
    long long int ctr=0;
    for(long long int i=1;i<=m;i++){
        if(taken[i]==0){
            ctr++;
        }else{
            if(ctr>0LL){
                sm=sm+ctr;
                i=who[i]+ctr;
                ctr=0;
            }
        }
    }
    if(ctr>0LL)
        sm=sm+ctr;
    long long int sm2=0;
    long long int ctr2=0;
    for(long long int i=m;i>=1;i--){
        if(taken[i]==0){
            ctr2++;
        }else{
            if(ctr2>0LL){
                sm2=sm2+ctr2;
                i=who2[i]-ctr2;
                ctr2=0;
            }
        }
    }
    if(ctr2>0LL)
        sm2=sm2+ctr2;
    cout<<min(sm,sm2);
    return 0;
}

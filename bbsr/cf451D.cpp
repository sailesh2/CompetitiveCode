#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int alarms[n];
    int has[n];
    for(int i=0;i<n;i++){
        cin>>alarms[i];
        has[i]=0;
    }
    sort(alarms,alarms+n);
    int off=0,ctr=0;
    int j=0;
    for(int i=0;i<n;i++){
        ctr=ctr+1;
        has[i]=1;
        if(ctr==k){
            while(j<i && alarms[i]-alarms[j]+1>m){
                if(has[j]==1)
                    ctr--;
                j++;
            }
            if(ctr==k){
                off++;
                has[i]=0;
                ctr--;
            }
        }
    }
    cout<<off;
    return 0;
}

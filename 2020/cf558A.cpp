#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int has[1005]={0};
    int ctr=0;
    int j=0,taken=0;
    for(int i=0;i<n && j<m;i++){
        if(ctr==1){
            has[i]=1;
            taken++;
            j++;
        }
        ctr=1-ctr;
    }

    for(int i=0;i<n && j<m;i++){
        if(has[i]==0){
            has[i]=1;
            j++;
        }

    }

    ctr=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(has[i]==0)
        cnt=1;
        if(has[i]==0 && has[(i-1+n)%n]==1)
            ctr++;
    }
    if(ctr==0 && cnt==1)
        ctr=1;
    cout<<ctr;
    return 0;
}

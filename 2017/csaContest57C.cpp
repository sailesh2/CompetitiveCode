#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int x;
    int fh[100005]={0};
    int has[100005]={0};
    for(int i=0;i<k;i++){
        cin>>x;
        fh[x]=1;
    }
    for(int i=0;i<k;i++){
        cin>>x;
        fh[x]=2;
    }
    int ctr=0,a,b;
    for(int i=1;i<=n;i++){
        if(fh[i]==1){
            b=i-1;
            if(b==0)
                b=n;
            a=i+1;
            if(a==n+1)
                a=1;
            if(has[b]==0 && fh[b]==2){
                has[b]=1;
                ctr++;
            }else if(has[a]==0 && fh[a]==2){
                has[a]=1;
                ctr++;
            }
        }
    }
    cout<<ctr+2*(k-ctr);
    return 0;
}

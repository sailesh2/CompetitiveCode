#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a,b;
    int has[n+1];
    int ctr[n+1];
    for(int i=0;i<n;i++){
        cin>>a;
        has[a]=i;
        ctr[i]=0;
    }
    ctr[n]=0;
    for(int i=0;i<n;i++){
        cin>>b;
        ctr[(has[b]-i+n)%n]++;
    }
    int maxi=0;
    for(int i=0;i<=n;i++)
        maxi=max(maxi,ctr[i]);

    cout<<maxi;
    return 0;
}

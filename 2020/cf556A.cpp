#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,r;
    cin>>n>>m>>r;

int maxi,mini,x;
    for(int i=0;i<n;i++){
        cin>>x;
        if(i==0)
            mini=x;
        else
            mini=min(mini,x);
    }

    for(int i=0;i<m;i++){
        cin>>x;
        if(i==0)
            maxi=x;
        else
            maxi=max(maxi,x);
    }

    int noOFShares = r/mini;
    int gain = max(0,maxi*noOFShares - mini*noOFShares);
    cout<<r+gain;
    return 0;
}

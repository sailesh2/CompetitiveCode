#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,ctr=0,t,x,maxi=0,mini=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t>>x;
        if(t==0)
            ctr=ctr+x;
        else
            ctr=ctr-x;
        maxi=max(maxi,ctr);
        mini=min(mini,ctr);
    }
    cout<<maxi+abs(mini);
    return 0;

}

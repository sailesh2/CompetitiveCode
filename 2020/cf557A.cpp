#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,h;
    cin>>n>>h>>m;
    int l,r,x;
    int rest[n+1];
    for(int i=1;i<=n;i++)
        rest[i]=h;
    for(int i=0;i<m;i++){
        cin>>l>>r>>x;
        for(int j=l;j<=r;j++){
            rest[j]=min(rest[j],x);
        }
    }

    int profit=0;
    for(int i=1;i<=n;i++){
        profit=profit+rest[i]*rest[i];
    }
    cout<<profit;
    return 0;
}

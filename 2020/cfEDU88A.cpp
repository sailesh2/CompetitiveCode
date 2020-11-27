#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,m,k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>k;

        int cardsPerPlayer = n/k;
        int maxCards = min(cardsPerPlayer,m);
        int remainingCards = m - maxCards;
        int ans;
        if(k-1>0)
        ans=maxCards - (remainingCards/(k-1) + (remainingCards%(k-1)==0?0:1));
        else
        ans=maxCards;
        cout<<ans<<"\n";
    }
    return 0;
}

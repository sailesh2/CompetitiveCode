#include<bits/stdc++.h>

using namespace std;

int getHighestFactor(int n){
    int maxi=1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int f = i;
            int s = n/i;
            maxi=max(maxi,f);
            maxi=max(maxi,s);
        }
    }

    return maxi;
}

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int k1=getHighestFactor(n);
        cout<<k1<<" "<<n-k1<<"\n";
    }
    return 0;
}

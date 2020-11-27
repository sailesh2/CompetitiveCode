#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int t,n,r;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>n>>r;
        long long int d = min(n-1,r);
        long long int v = (d*(d+1))/2;
        if(d<r)
            v++;
        cout<<v<<"\n";
    }
    return 0;
}

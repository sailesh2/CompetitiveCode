#include<bits/stdc++.h>

using namespace std;
long long int ans[200005];
long long int MAX=10000000000;
long long int n,c;
void calDP(long long int*a, long long int*b){
    long long int dpS[n],dpL[n];
    dpS[0]=0;
    dpL[0]=MAX;
    ans[0]=0;

    for(long long int i=1;i<n;i++){
        dpL[i]=min(dpS[i-1]+b[i]+c,dpL[i-1]+b[i]);
        dpS[i]=min(dpS[i-1]+a[i],dpL[i-1]+a[i]);
        ans[i]=min(dpL[i],dpS[i]);
    }
}
int main(){
    cin>>n>>c;
    long long int a[n],b[n];
    for(long long int i=1;i<n;i++){
        cin>>a[i];
    }
    for(long long int i=1;i<n;i++){
        cin>>b[i];
    }
    calDP(a,b);
    for(long long int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}

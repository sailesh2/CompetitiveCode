#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,c;
    cin>>n>>c;
    long long int a[n],b[n];
    for(long long int i=1;i<n;i++){
        cin>>a[i];
    }
    for(long long int i=1;i<n;i++){
        cin>>b[i];
    }
    long long int ans[n];
    ans[0]=0;
    long long int cnt=0;
    for(long long int i=1;i<n;i++){
        if(cnt==1){
            if(a[i]<b[i])
            cnt=0;
            ans[i]=ans[i-1]+min(a[i],b[i]);
        }
        else{
            if((b[i]+c)<a[i])
            cnt=1;
            ans[i]=ans[i-1]+min(a[i],b[i]+c);
        }
    }
    for(long long int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}

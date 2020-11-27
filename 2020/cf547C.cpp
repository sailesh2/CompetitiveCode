#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int q[n];
    int start=1;
    int p[n];
    int p2[n];
    p[0]=start;
    p2[0]=start;
    int mini=start;
    for(int i=0;i<n-1;i++){
        cin>>q[i];
        p[i+1]=p[i]+q[i];
        p2[i+1]=p[i+1];
        mini=min(mini,p[i+1]);
    }
    if(mini<=0){
    for(int i=0;i<n;i++){
        p[i]=p[i]+abs(mini)+1;
        p2[i]=p[i];
    }
    }
    sort(p2,p2+n);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(p2[i]!=i+1){
            cnt=1;
            break;
        }
    }
    if(cnt==0){
        for(int i=0;i<n;i++){
            cout<<p[i]<<" ";
        }
    }else{
        cout<<"-1";
    }
    return 0;
}

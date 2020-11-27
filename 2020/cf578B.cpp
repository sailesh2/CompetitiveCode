#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m,k;
        cin>>n>>m>>k;
        int blocks[n];
        for(int j=0;j<n;j++){
            cin>>blocks[j];
        }

        int cnt=0;

        for(int j=0;j<n-1;j++){
            m=m+blocks[j]-(max(0,blocks[j+1]-k));
            if(m<0){
                cnt=1;
                break;
            }
        }
        if(cnt==0){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}

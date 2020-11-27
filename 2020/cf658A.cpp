#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,m,x;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        int has[10000]={0};
        for(int j=0;j<n;j++){
            cin>>x;
            has[x]=1;
        }
        int save=-1;
        for(int j=0;j<m;j++){
            cin>>x;
            if(has[x]==1){
                save=x;
            }
        }
        if(save==-1)
            cout<<"NO\n";
        else
            cout<<"YES\n1 "<<save<<"\n";
    }
    return 0;
}

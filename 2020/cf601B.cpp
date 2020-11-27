#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,m,s,x;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        s=0;
        for(int j=0;j<n;j++){
            cin>>x;
            s=s+x;
        }
        if(n==2){
            cout<<"-1\n";
        }else if(m<n){
            cout<<"-1\n";
        }else{
            cout<<2*s<<"\n";
            for(int j=1;j<=n;j++){
                if(j==n)
                cout<<j<<" 1\n";
                else
                cout<<j<<" "<<j+1<<"\n";
            }
            for(int j=0;j<m-n;j++){
                cout<<"1 2\n";
            }
        }
    }
    return 0;
}

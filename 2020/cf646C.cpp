#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,x;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>x;
        int ctr=0;
        int u,v;
        for(int j=0;j<n-1;j++){
            cin>>u>>v;
            if(u==x || v==x){
                ctr++;
            }
        }
        if(ctr<=1){
            cout<<"Ayush\n";
        }else{
            if((n-1)%2!=0){
                cout<<"Ayush\n";
            }else{
                cout<<"Ashish\n";
            }
        }
    }
    return 0;
}

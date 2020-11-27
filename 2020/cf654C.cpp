#include<bits/stdc++.h>

using namespace std;


int main(){
    long long int t,v,c,n,m;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>v>>c>>n>>m;
        if(v>c){
            if(n>v || m>c){
                cout<<"No\n";
            }else{
                cout<<"Yes\n";
            }
        }else{
            if(n>c || m>v){
                cout<<"No\n";
            }else{
                cout<<"Yes\n";
            }
        }
    }
    return 0;
}

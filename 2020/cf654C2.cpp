#include<bits/stdc++.h>

using namespace std;


int main(){
    long long int t,v,c,n,m;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>v>>c>>n>>m;
        {
            if(v>c){
                if(c>=m){
                    c=c-m;
                    if(v+c>=n){
                        cout<<"Yes\n";
                    }else{
                        cout<<"No\n";
                    }
                }else{
                    cout<<"No\n";
                }
            }else{
                if(v>=m){
                    v=v-m;
                    if(v+c>=n){
                        cout<<"Yes\n";
                    }else{
                        cout<<"No\n";
                    }
                }else{
                    cout<<"No\n";
                }
            }
        }
    }
    return 0;
}

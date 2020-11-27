#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int b,p,c;
        cin>>b>>p>>c;
        int ham,chi;
        cin>>ham>>chi;
        int cost=0;
        if(chi>ham){
            if(2*c>b){
                cost=cost+(b/2)*chi;
                b=b%2;
            }else{
                cost=cost+(c)*chi;
                b=b-(2*c);
            }
            if(2*p>b){
                cost=cost+(b/2)*ham;
                b=b%2;
            }else{
                cost=cost+(p)*ham;
                b=b-(2*p);
            }
        }else{
            if(2*p>b){
                cost=cost+(b/2)*ham;
                b=b%2;
            }else{
                cost=cost+(p)*ham;
                b=b-(2*p);
            }
             if(2*c>b){
                cost=cost+(b/2)*chi;
                b=b%2;
            }else{
                cost=cost+(c)*chi;
                b=b-(2*c);
            }
        }
        cout<<cost<<"\n";
    }
    return 0;
}

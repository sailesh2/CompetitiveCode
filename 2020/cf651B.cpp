#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,x;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        vector<int> ev,od;
        for(int j=0;j<2*n;j++){
            cin>>x;
            if(x%2==0)
                ev.push_back(j+1);
            else
                od.push_back(j+1);
        }
        int evc=ev.size();
        int odc=od.size();
        if(evc%2==0 && odc%2==0){
            if(evc>=2){
                for(int j=2;j<evc;j=j+2){
                    cout<<ev[j]<<" "<<ev[j+1]<<"\n";
                }
                for(int j=0;j<odc;j=j+2){
                    cout<<od[j]<<" "<<od[j+1]<<"\n";
                }
            }else{
                for(int j=0;j<evc;j=j+2){
                    cout<<ev[j]<<" "<<ev[j+1]<<"\n";
                }
                for(int j=2;j<odc;j=j+2){
                    cout<<od[j]<<" "<<od[j+1]<<"\n";
                }
            }
        }else{
                for(int j=1;j<evc;j=j+2){
                    cout<<ev[j]<<" "<<ev[j+1]<<"\n";
                }
                for(int j=1;j<odc;j=j+2){
                    cout<<od[j]<<" "<<od[j+1]<<"\n";
                }
        }
    }
    return 0;
}

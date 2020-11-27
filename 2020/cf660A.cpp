#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        if(n<=30)
            cout<<"NO\n";
        else{
            int th = n-30;
            if(th!=6 && th!=10 && th!=14){
                cout<<"YES\n";
                cout<<"6 10 14 "<<th<<"\n";
            }else if(n-31>0 && n-31!=6 && n-31!=10 && n-31!=15){
                cout<<"YES\n";
                cout<<"6 10 15 "<<n-31<<"\n";
            }else if(n-37>0 && n-37!=6 && n-37!=10 && n-37!=15){
                cout<<"YES\n";
                cout<<"6 10 21 "<<n-37<<"\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}

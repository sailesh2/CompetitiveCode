#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,x,y;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>x;
        int ev=0;
        int od=0;
        for(int j=0;j<n;j++){
            cin>>y;
            if(y%2==0)
                ev++;
            else
                od++;
        }
        int cnt=0;
        if(x%2==0){
            cnt=0;
            for(int j=1;j<=x;j=j+2){
                if(ev>=j && od>=(x-j)){
                    cnt=1;
                    break;
                }
            }

        }else{
            cnt=0;
            for(int j=1;j<=x;j=j+2){
                if(od>=j && ev>=(x-j)){
                    cnt=1;
                    break;
                }
            }
        }

        if(cnt==1){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}

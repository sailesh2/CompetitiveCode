#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int a;
        int cnt=0,ctr=0;
        for(int j=0;j<n;j++){
            cin>>a;
            if(cnt==0){
                if(a==1)
                    ctr++;
                else
                    cnt=1;
            }
        }
        if(cnt==0){
            if(ctr%2==0){
                cout<<"Second\n";
            }else{
                cout<<"First\n";
            }
        }else{
            if(ctr%2==0){
                cout<<"First\n";
            }else{
                cout<<"Second\n";
            }
        }
    }
    return 0;
}

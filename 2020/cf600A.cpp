#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int a[n],b[n];
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=0;j<n;j++){
            cin>>b[j];
        }
        int cnt=0;
        int save=-1;
        int last=-1;
        for(int j=0;j<n;j++){
            if(a[j]!=b[j]){
                if(save==-1){
                    save=b[j]-a[j];
                    last=j;
                    if(save<=0){
                        cnt=1;
                        break;
                    }
                }else{
                    if(b[j]-a[j]!=save){
                        cnt=1;
                        break;
                    }
                    if(last!=j-1){
                        cnt=1;
                        break;
                    }
                    last=j;
                }
            }
        }
        if(cnt==0){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }

    }
    return 0;
}

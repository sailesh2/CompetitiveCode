#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    string x,y;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>x>>y;
        int save=0;
        for(int i=y.length()-1;i>=0;i--){
            if(y[i]=='1'){
                save=y.length()-1-i;
                break;
            }
        }
        int ans=0;
        for(int i=x.length()-1;i>=0;i--){
            if(x[i]=='1'){
                int save2=x.length()-1-i;
                if(save2-save>=0){
                    ans=save2-save;
                    break;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,l,g;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        set<int> taken;
        int save=-1;
        for(int j=0;j<n;j++){
            cin>>l;
            int cnt=0;
            for(int k=0;k<l;k++){
                cin>>g;
                if(cnt==0 && taken.count(g)==0){
                    taken.insert(g);
                    cnt=1;
                }
            }
            if(cnt==0){
                save=j;
            }
        }
        if(save!=-1){
            int saveK=-1;
            for(int j=1;j<=n;j++){
                if(taken.count(j)==0){
                    saveK=j;
                    break;
                }
            }
            if(saveK==-1){
                cout<<"OPTIMAL\n";
            }else{
                cout<<"IMPROVE\n";
                cout<<save+1<<" "<<saveK<<"\n";
            }
        }else{
            cout<<"OPTIMAL\n";
        }
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,d,h;
    cin>>n>>d>>h;
    vector<int> tree[n+1];
    int root=1;
    int ctr=root+1;
    for(int i=0;i<h;i++){
        tree[root].push_back(ctr);
        root=ctr;
        ctr++;
    }
    root=1;
    int cnt=0,cnt2=0,dExists=0,toPush;
    for(int i=0;i<d-h;i++){
        dExists=1;
        tree[root].push_back(ctr);
        root=ctr;
        ctr++;
        cnt++;
        if(cnt>h){
            cnt2=1;
            break;
        }
    }
    if(cnt2==1){
        cout<<"-1";
    } else{
        toPush=1;
        if(dExists==0 && ctr<=n){
            if(ctr>3){
                toPush=2;
            }else{
                cnt2=1;
            }
        }

        if(cnt2==1){
            cout<<"-1";
        }else{

            for(;ctr<=n;ctr++){
                tree[toPush].push_back(ctr);
            }
            for(int i=1;i<=n;i++){
                for(int j=0;j<tree[i].size();j++){
                    cout<<i<<" "<<tree[i][j]<<"\n";
                }
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

set<int> has;

int binSear(int cost){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<k && pc2[save+ctr]<=cost){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    if(save==-1)
        return -1;
    return p2[save];
}

int main(){
    int n,m,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        has.insert(x);
    }
    int p=0;
    for(int i=0;i<m;i++){
        cin>>x;
        x=x^p;
        cout<<binSear(x)<<"\n";
        p=x;
    }
    return 0;
}

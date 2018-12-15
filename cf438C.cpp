#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,q,t,r,c,x;
    cin>>n>>m>>q;
    for(int i=0;i<q;i++){
        cin>>t;
        if(t==3){
            cin>>r>>c>>x;
        }else{
            cin>>x;
        }

        if(t==1){
            row[x-1]=(row[x-1]+1)%n;
        }else if(t==2){
            col[x-1]=(col[x-1]+1)%m;
        } else{
            rotations[r-1][c-1]=
        }
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int ny=y;

    for(int j=x;j>=1;j--){
        cout<<j<<" "<<y<<"\n";
        for(int i=1;i<y;i++){
            cout<<j<<" "<<i<<"\n";
            ny=i;
        }
        for(int i=y+1;i<=m;i++){
            cout<<j<<" "<<i<<"\n";
            ny=i;
        }
        y=ny;
    }

    for(int j=x+1;j<=n;j++){
        cout<<j<<" "<<y<<"\n";
        for(int i=1;i<y;i++){
            cout<<j<<" "<<i<<"\n";
            ny=i;
        }
        for(int i=y+1;i<=m;i++){
            cout<<j<<" "<<i<<"\n";
            ny=i;
        }
        y=ny;
    }

    return 0;
}

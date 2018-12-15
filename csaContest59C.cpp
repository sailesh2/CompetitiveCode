#include<bits/stdc++.h>

using namespace std;

int main(){
    int g1,p1,g2,p2;
    cin>>g1>>p1>>g2>>p2;
    int savef=g1+1;
    int v;
    for(int i=0;i<=g1;i++){
        v=(int)floor(((float)i/g1)*100);
        if(v==p1){
            savef=min(savef,i);
        }
    }

    int savel=-1;

    for(int i=0;i<=g2;i++){
        v=(int)floor(((float)i/g2)*100);
        if(v==p2){
            savel=max(savel,i);
        }
    }
    if(savel-savef>g2-g1)
        cout<<g2-g1;
    else
        cout<<savel-savef;
    return 0;
}

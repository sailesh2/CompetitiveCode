#include<bits/stdc++.h>

using namespace std;

int main(){
    int q,d,l,r;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>l>>r>>d;
        if(d<l){
            cout<<d<<"\n";
        }else{
            cout<<d*(r/d + 1)<<"\n";
        }
    }
    return 0;
}

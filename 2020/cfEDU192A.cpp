#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    int l,r;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>l>>r;
        if(l*2>r){
            cout<<"-1 -1\n";
        }else{
            cout<<l<<" "<<2*l<<"\n";
        }
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin>>q;
    int l1,r1,l2,r2;
    for(int i=0;i<q;i++){
        cin>>l1>>r1>>l2>>r2;

        if(l1==r2){
            cout<<r1<<" "<<r2;
        }else{
            cout<<l1<<" "<<r2;
        }
        cout<<"\n";
    }
    return 0;
}

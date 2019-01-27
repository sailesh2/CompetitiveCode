#include<bits/stdc++.h>

using namespace std;

int main(){
    int q,l1,r1,l2,r2;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>l1>>r1>>l2>>r2;
        if(min(l1,r1) != max(l2,r2))
            cout<<min(l1,r1)<<" "<<max(l2,r2)<<"\n";
        else
            cout<<max(l1,r1)<<" "<<min(l2,r2)<<"\n";
    }
    return 0;
}


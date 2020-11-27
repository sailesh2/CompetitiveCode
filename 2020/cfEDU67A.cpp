#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    int egg,st,toy;
    for(int i=0;i<t;i++){
        cin>>egg>>st>>toy;
        int diff = st+toy-egg;
        int m = max(st,toy);
        cout<<m - diff + 1<<"\n";
    }
    return 0;
}

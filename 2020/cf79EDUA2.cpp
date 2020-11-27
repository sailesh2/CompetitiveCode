#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    int r,g,b;
    for(int i=0;i<t;i++){
        cin>>r>>g>>b;
        vector<int> v;
        v.push_back(r);
        v.push_back(g);
        v.push_back(b);
        sort(v.begin(),v.end());

        v[2]=v[2]-v[1];
        if(v[2]-v[0]>1){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
        }
    }
    return 0;
}
